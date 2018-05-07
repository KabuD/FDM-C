import serial
import time
import csv
import struct
import datetime
############################################GETTING DATA

ser = serial.Serial(
    port='COM4',\
    baudrate=460000,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
    timeout=0.5)
    			
counter = 2000 # numbers of packages that will be sent 
len_dataframe= 23 #number of bytes each pakage will have 

packages=[]

ser.write(b'0')
if ser.is_open:
	while counter != 0:
		packages.append(ser.read(len_dataframe));
		counter-=1
else:
	print("port zamkniety")
ser.close()
############################################CHECKING DATA

while True:
	dataframe_error=0;
	checkSum_error=0
	no_error=0
	packages_failed=[]
	print("Number of packages",len(packages))

	for x in range (0,len(packages)-1):
		if(packages[x][0]==0x01 and packages[x][len(packages[x])-2]==0x02 and len(packages[x])==len_dataframe): # if there s start 0x01 and stop 0x02 and lenght is appropriate
			buff=sum(packages[x][1:len(packages[x])-2]) #getting the checksum
			if(packages[x][len(packages[x]) -1] ==(0x000000FF & buff)):# if last byte of checksum is good
				no_error=no_error+1
			else: # if last byte of checksum is not good 
				checkSum_error=checkSum_error+1
				packages_failed.append(x)
				print("CHECKSUM_ERROR: Package",x,"True_checkSum", (0x000000FF & buff),"Given_checkSum",packages[x][len(packages[x]) -1])
		else: # if there is no start 0x01 and stop 0x02 and length is not appropriate
			dataframe_error=dataframe_error+1
			packages_failed.append(x)
			print("DATAFRAME_ERROR: Package",x,"START BIT",packages[x][0],"STOP BIT",packages[x][len(packages[x]) -2],"LENGTH", len(packages[x]))

	print("DATAFRAME_error counter",dataframe_error)
	print("CHECKSUM_error counter", checkSum_error)
	print("NO_ERROR counter", no_error) 
	############################################GETTING BADLY DOWNLOADED DATA AGAIN
	
	if(dataframe_error or checkSum_error):
		packages_failed_bytes=[]

		packages_failed_bytes.append(20) # begining of data frame
		packages_failed_bytes.append(len(packages_failed))
				
		for i in range(0,len(packages_failed)):
			if(packages_failed[i]>255):
				buff=packages_failed[i].to_bytes(2,'big')
				packages_failed_bytes.append(buff[0])
				packages_failed_bytes.append(buff[1])
			else:
				packages_failed_bytes.append(0x00)
				packages_failed_bytes.append(packages_failed[i])

		to_send = ''
		for i in packages_failed_bytes:
			to_send = struct.pack('!{0}B'.format(len(packages_failed_bytes)), *packages_failed_bytes)
					
		if ser.is_open:
			ser.write(to_send)
		else:
			ser.open()
			ser.write(to_send)

		if ser.is_open:
			for i in range(0,len(packages_failed)):
				packages[packages_failed[i]]=ser.read(len_dataframe)
		else:
			ser.close()
	if(checkSum_error==0 and dataframe_error==0):
		break
############################################CALCULATING MEASUREMENTS

measurements=[]
 
for x in range(0,len(packages)):
	for y in range(1,len(packages[x])-3,2):
		val=packages[x][y]*256 +packages[x][y+1]
		if(val!=0): # removing zeroes that happen in the few last places of 20000 measurements
			measurements.append(round((((packages[x][y]*256 +packages[x][y+1])-32768)*0.64)/1000,6)) # conversion from 'uint16' to Ampers rounded to 6th  
############################################SAVING MEASUREMENTS

name=datetime.datetime.now().strftime("%I-%M-%S-%d-%b-%Y") +".csv"
with open(name, 'w', newline='') as csvfile:
	writer = csv.writer(csvfile, delimiter=';',quotechar='|', quoting=csv.QUOTE_NONE)
	for x in range(0,len(measurements)):
		writer.writerow([str(measurements[x])])
	 
