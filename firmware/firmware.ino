
//arduino mini
// pwms =  3 , 5, 6, 9, 10, 12

// m1 = 3, 2 - 4

// m2 = 5, 7 - 8

// m3 = 6, 10 - 11
 				
// m4 = 9, 12-13

// m5 = 3, 2-4a
//pines analogicos
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//3v  265-402
//5v  316-481

// 90 =~ 5v (pwm) 
// los pwms , se programan dependiendo al consumo
// del motor

int minVal = 316;
int maxVal = 480;

void setup() {
	Serial.begin( 9600 );
	
	// m1

	pinMode( 3 , 1 );
	pinMode( 2 , 1 );
	pinMode( 4 , 1 );
	analogWrite( 3 , 140 );

	// m2
	pinMode( 5 , 1 );
	pinMode( 7 , 1 );
	pinMode( 8 , 1 );
	analogWrite( 5 , 135 );

	// m3
	pinMode( 6 , 1 );
	pinMode( 10 , 1 );
	pinMode( 11 , 1 );
	analogWrite( 6 , 120 );

	// m4 = 9, 12-13
	pinMode( 9 , 1 );
	pinMode( 12 , 1 );
	pinMode( 13 , 1 );
	analogWrite( 9 , 135 );	


}


void loop() {

	if( Serial.available() ){
	    byte val = Serial.read();
	    switch ( val ) {
	    	/*
	    		m1
			    a = 97
			    s = 115
			    d = 100
			*/	
	        case 97:
	        	parar( 2 , 4 );
				digitalWrite( 2 , 1 );
				digitalWrite( 4 , 0 );
				delay( 200 );
	          break;
	        case 115:
	        	parar( 2 , 4 );
	          break;
	        case 100:
	        	parar( 2 , 4 );
				digitalWrite( 2 , 0 );
				digitalWrite( 4 , 1 );
				delay( 200 );
	          break;
	        /*
	        	m2
				q = 113
				w = 119
				e = 101
	        */ 
	        case 113:
	        	parar( 7 , 8 );
				digitalWrite( 7 , 1 );
				digitalWrite( 8 , 0 );
				delay( 200 );
	          break;
	        case 119:
	        	parar( 7 , 8 );
	          break;
	        case 101:
	        	parar( 7 , 8 );
				digitalWrite( 7 , 0 );
				digitalWrite( 8 , 1 );
				delay( 200 );
	          break;
	        /*
	        	m3
				z = 122
				x = 120
				c = 99
	        */ 
	        case 122:
	        	digitalWrite( 6 , 1 );
	        	parar( 10 , 11 );
				digitalWrite( 10 , 1 );
				digitalWrite( 11 , 0 );
				delay( 200 );
	          break;
	        case 120:
	        	parartest( 6 );
	          break;
	        case 99:
	        	digitalWrite( 6 , 1 );
	        	parar( 10 , 11 );
				digitalWrite( 10 , 0 );
				digitalWrite( 11 , 1 );
				delay( 200 );
	          break;
	        /*
	        	m4
				i = 105
				o = 111
				p = 112
	        */ 
	        case 105:
	        	parar( 12 , 13 );
				digitalWrite( 12 , 1 );
				digitalWrite( 13 , 0 );
				delay( 200 );
	          break;
	        case 111:
	        	parar( 12 , 13 );
	          break;
	        case 112:
	        	parar( 12 , 13 );
				digitalWrite( 12 , 0 );
				digitalWrite( 13 , 1 );
				delay( 200 );
	          break;
	    }
	}
/*
	int xRead = analogRead(xPin);
	delay(1);
	int xAng = map(xRead, minVal, maxVal, -90, 90);
	if( xAng < -75 || xAng > 75   ){
	    parar();
	}
*/

	delay( 5 );
}

void parar( int i , int j ){
	digitalWrite( i , 0 );
	digitalWrite( j , 0 );
	delay(100);
}

void parartest( int i ){
	analogWrite( i , 5e0 );
	delay(100);
}
