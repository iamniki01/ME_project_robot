import RPi.GPIO as GPIO
import serial
import time

motor1=(3,5)
motor2=(7,11)
flamesensor=(16)
gassensor=(18)
buzzer=(29)
led=(31)

GPIO.setmode(GPIO.BOARD)
GPIO.setup(motor1,GPIO.OUT) 
GPIO.setup(motor2,GPIO.OUT)
GPIO.setup(flamesensor,GPIO.IN)
GPIO.setup(gassensor,GPIO.IN)
GPIO.setup(buzzer,GPIO.OUT)
GPIO.setup(led,GPIO.OUT)

data=serial.Serial('/dev/ttyS0',9600)

while 1:
	fwd=data.read()
	time.sleep(0.3)
	#data.write("hello")
	#time.sleep(1)
	print(fwd)
	if(fwd=='f'):
		print('move fwd')
		GPIO.output(motor1,(1,0))
		GPIO.output(motor2,(1,0))
	elif(fwd=='b'):
		print('move bckwd')
                GPIO.output(motor1,(0,1))
                GPIO.output(motor2,(0,1))
        elif(fwd=='r'):
                print('move right')
                GPIO.output(motor1,(0,1))
                GPIO.output(motor2,(1,0))
        elif(fwd=='l'):
                print('move left')
                GPIO.output(motor1,(1,0))
                GPIO.output(motor2,(0,1))
	elif(fwd=='s'):
		print('stop')
                GPIO.output(motor1,(0,0))
                GPIO.output(motor2,(0,0))


temp=0


while True:
         
sensor_state = GPIO.input(16)
        
 time.sleep(0.3)
       
  if (button_state == False and temp == False):
   
          GPIO.output(buzzer, True)
	  GPIO.output(led, True)
	   
  temp = 1
          
   print('FIRE On...')
     
        time.sleep(1)
        
 elif (button_state == False and temp == True):
	  
   GPIO.output(buzzer,False)
   GPIO.output(led, False)	  
   temp = 0
         
    print('Button off...')

	     time.sleep(1)

temp=2


while True:
         
sensor2_state = GPIO.input(18)
        
 time.sleep(0.3)
       
  if (button_state == False and temp == False):
   
          GPIO.output(buzzer, True)
	  GPIO.output(led, True)
	   
  temp = 3
          
   print('Explosive material found...')
     
        time.sleep(1)
        
 elif (button_state == False and temp == True):
	  
   GPIO.output(buzzer,False)
   GPIO.output(led, False)	  
   temp = 0
         
    print('Button off...')

	     time.sleep(1)