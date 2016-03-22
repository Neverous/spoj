#2009
#Maciej Szeptuch
#XIV LO Wrocław

data = STDIN . gets
tests = data . to_i
tab = {
	13 => {
		'M' => [ 152, 261 ],
		'W' => [ 154, 254 ],
	},
	14 => {
		'M' => [ 157, 264 ],
		'W' => [ 160, 263 ],
	},
	15 => {
		'M' => [ 163, 268 ],
		'W' => [ 166, 268 ],
	},
	16 => {
		'M' => [ 169, 273 ],
		'W' => [ 169, 272 ],
	},
	17 => {
		'M' => [ 175, 278 ],
		'W' => [ 172, 273 ],
	},
	18 => {
		'M' => [ 179, 282 ],
		'W' => [ 174, 274 ],
	},
	19 => {
		'M' => [ 183, 186 ],
		'W' => [ 175, 274 ],
	},
}
for t in (1..tests) :
	sex, age, size, weight = STDIN . gets . split
	age = age . to_i
	size = size . to_i
	weight = weight . to_i
	bmi = weight * 1000000 / ( size * size )
	if bmi % 10 > 5 :
		bmi += 10
	
	else 
		if bmi % 10 == 5 and ( bmi / 10 ) % 10 :
			bmi += 10
		end
	end
	
	bmi /= 10
	warning = ""
	if tab [ age ] [ sex ] [ 0 ] > bmi or tab [ age ] [ sex ] [ 1 ] < bmi
		warning = " WARNING"
	end
	bmi *= 0.1

	STDOUT . puts "%0.1f%s" % [bmi, warning]
end
