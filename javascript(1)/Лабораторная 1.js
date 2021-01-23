'use strict'

const arr = [true, 'hello', 5, 12, -200, false, false, 'word', 43, false]
let hash = { number: 0, string: 0, boolean: 0 }

function filter(){
	for (let i in arr){
		val = arr[i]
		if (typeof val === 'number'){
			hash.number = hash.number + 1
		}
		else if (typeof val === 'string'){
			hash.string = hash.string + 1
		}
		else if (typeof val === 'boolean'){
			hash.boolean = hash.boolean + 1
		}
	}
}
filter()
console.log(hash)

'use strict'


const rangeOdd = (start, end) =>{
	let arr = []

	while (start < end){
		start = start + 1
		while (start % 2 === 0){
			arr.push(start)
		}
	}
} 
rangeOdd(15,30)


'use strict';

const square = x =>{
	return x ** 2;
}
const cube = y =>{
	return x ** 3;
}
const average = (a, b) =>{
	return a + b / 2;
}
function calculate(){
	let arr = [];
	i = 0
	while (i < 9){
		const square = x =>{
			m = x ** 2
			return m;

		}
		const cube = j =>{
			g = j ** 3
			return g;
		}
		square(i)
		cube(i)
		const average = (a, b) =>{
			h = (a + b) / 2
			return h;
		}
		average(m,g)
		arr.push(h)
		i++;

	}
	return arr;

}
console.log(calculate())