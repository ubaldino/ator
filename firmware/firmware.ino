
//arduino mini
// pwms =  3 , 5, 6, 9, 10, 12
// m1 = 3, 2 - 4
// m2 = 5, 7 - 8
// m3 = 6, 10 - 11
// m4 = 9, 12-13
// m5 = 3, 2-4a


//arduino MEGA
// pwms =  2 , 3, 4, 5, 6, 7
// m1 = 2, 30 - 31
// m2 = 3, 32 - 33
// m3 = 4, 34 - 35
// m4 = 5, 36 - 37
// m5 = 6, 38 - 39
// m6 = 7, 40 - 41

//         vcc 	 x    y    z
// acel1 = 47 , 49 , 51 , 53 
// acel2 = 46 , 48 , 50 , 52 
// acel3 =  

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
	
	// m1 = 2, 30 - 31
	pinMode( 2 , 1 );
	pinMode( 30 , 1 );
	pinMode( 31 , 1 );
	analogWrite( 2 , 140 );

	// m2 = 3, 32 - 33
	pinMode( 3 , 1 );
	pinMode( 32 , 1 );
	pinMode( 33 , 1 );
	analogWrite( 3 , 135 );

	// m3 = 4, 34 - 35
	pinMode( 4 , 1 );
	pinMode( 34 , 1 );
	pinMode( 35 , 1 );
	analogWrite( 4 , 120 );

	// m4 = 5, 36 - 37
	pinMode( 5 , 1 );
	pinMode( 36 , 1 );
	pinMode( 37 , 1 );
	analogWrite( 5 , 135 );	
	
	// m5 = 6, 38 - 39
	pinMode( 6 , 1 );
	pinMode( 38 , 1 );
	pinMode( 39 , 1 );
	analogWrite( 6 , 135 );
	
	// m6 = 7, 40 - 41
	pinMode( 7 , 1 );
	pinMode( 40 , 1 );
	pinMode( 41 , 1 );
	analogWrite( 7 , 135 );

	pinMode(13, 1);
	digitalWrite(13, 1);


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
				// m1 = 2, 30 - 31
			*/	
	        case 97:
	        	parar( 30 , 31 );
				digitalWrite( 30 , 1 );
				digitalWrite( 31 , 0 );
				delay( 200 );
	          break;
	        case 115:
	        	parar( 30 , 31 );
	          break;
	        case 100:
	        	parar( 30 , 31 );
				digitalWrite( 30 , 0 );
				digitalWrite( 31 , 1 );
				delay( 200 );
	          break;
	        /*
	        	m2
				q = 113
				w = 119
				e = 101
				// m2 = 3, 32 - 33
	        */ 
	        case 113:
	        	parar( 32 , 33 );
				digitalWrite( 32 , 1 );
				digitalWrite( 33 , 0 );
				delay( 200 );
	          break;
	        case 119:
	        	parar( 32 , 33 );
	          break;
	        case 101:
	        	parar( 32 , 33 );
				digitalWrite( 32 , 0 );
				digitalWrite( 33 , 1 );
				delay( 200 );
	          break;
	        /*
	        	m3
				z = 122
				x = 120
				c = 99
				// m3 = 4, 34 - 35
	        */ 
	        case 122:
	        	parar( 34 , 35 );
				digitalWrite( 34 , 1 );
				digitalWrite( 35 , 0 );
				delay( 200 );
	          break;
	        case 120:
	        	parar( 34 , 35 );
	          break;
	        case 99:
	        	parar( 34 , 35 );
				digitalWrite( 34 , 0 );
				digitalWrite( 35 , 1 );
				delay( 200 );
	          break;
	        /*
	        	m4
				i = 105
				o = 111
				p = 112
				// m4 = 5, 36 - 37
	        */ 
	        case 105:
	        	parar( 36 , 37 );
				digitalWrite( 36 , 1 );
				digitalWrite( 37 , 0 );
				delay( 200 );
	          break;
	        case 111:
	        	parar( 36 , 37 );
	          break;
	        case 112:
	        	parar( 36 , 37 );
				digitalWrite( 36 , 0 );
				digitalWrite( 37 , 1 );
				delay( 200 );
	          break;
				// m5 = 6, 38 - 39
				// m6 = 7, 40 - 41
	    }

	}

	int xRead = analogRead(A0);
	delay(1);
	//3v  265-402
	//5v  316-481

	int xAng = map(xRead, 265, 402, -90, 90);
	Serial.println( xAng );

	if( xAng > 90 || xAng < -85 ){
	    parar( 30 , 31 );
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
