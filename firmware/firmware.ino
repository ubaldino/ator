
int ENA = 10; 
int ENB = 11; 

int IN1 = 2;
int IN2 = 3;

int IN3 = 5;
int IN4 = 4;
 
void setup() {
	Serial.begin( 9600 );

	pinMode( ENA , 1 );
	pinMode( IN1 , 1 );
	pinMode( IN2 , 1 );

	digitalWrite ( ENA , 1 );
	digitalWrite( IN1, 0 );
	digitalWrite( IN2, 0 );
}
/*
    a = 97
    s = 115
    d = 100
*/

void loop() {
	if( Serial.available() ){
	    byte val = Serial.read();
	    switch ( val ) {
	        case 97:
		        parar();
				digitalWrite( IN1, 1 );
				digitalWrite( IN2, 0 );
	          break;
	        case 115:
				parar();
	          break;
	        case 100:
				digitalWrite( IN1, 0 );
				digitalWrite( IN2, 1 );
	          break;
	    }
	}
	delay( 5 );
}

void parar(){
	digitalWrite( IN1, 0 );
	digitalWrite( IN2, 0 );
	delay( 100 );
}