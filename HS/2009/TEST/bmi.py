# -*- coding: utf-8 -*-
#2009
#Maciej Szeptuch
#XIV LO Wrocław
import sys

data = sys . stdin . read ( )
data = data . split ( u'\n' )
tests = int ( data [ 0 ] )
tab = {
	13 : {
		'M' : ( 152, 261 ),
		'W' : ( 154, 254 ),
	},
	14 : {
		'M' : ( 157, 264 ),
		'W' : ( 160, 263 ),
	},
	15 : {
		'M' : ( 163, 268 ),
		'W' : ( 166, 268 ),
	},
	16 : {
		'M' : ( 169, 273 ),
		'W' : ( 169, 272 ),
	},
	17 : {
		'M' : ( 175, 278 ),
		'W' : ( 172, 273 ),
	},
	18 : {
		'M' : ( 179, 282 ),
		'W' : ( 174, 274 ),
	},
	19 : {
		'M' : ( 183, 186 ),
		'W' : ( 175, 274 ),
	},
}
for t in xrange ( tests ) :
	sex, age, size, weight = data [ t + 1 ] . split ( )
	age = int ( age )
	size = int ( size )
	weight = int ( weight )
	bmi = weight * 1000000 / ( size * size )
	if bmi % 10 > 5 :
		bmi += 10
	
	elif bmi % 10 == 5 and ( bmi / 10 ) % 10 :
		bmi += 10
	
	bmi /= 10
	print "%0.1f" % ( 0.1 * bmi ), ( ( tab [ age ] [ sex ] [ 0 ] > bmi or tab [ age ] [ sex ] [ 1 ] < bmi ) and "WARNING" ) or ""
