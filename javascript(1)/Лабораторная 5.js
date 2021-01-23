const obj = { n: 23, b: 34 }

Object.prototype.map = function (fn) {
    let obj = this
    let result = {}
    for (let i of Object.keys(obj)) {
        result[i] = (fn(this[i]))
    }
    return result
}

console.log(obj.map(x => x * 2))
///
const f = (str, st, rep) => {
	let str1;
	if (str.includes(st)) {
		str1 = str.replace(st, rep)
	}
	return str1
}

console.log(f('dsd sas te', 'dsd', 'fas'))

///
class f {
	constructor() {
		this.col = new Map
	}
	add(key, value) {
		if (key && value) {
			this.col.set(key, value)
		}
	}
}

let nm = new f()
nm.add('key', 'value')
console.log(nm)


  Array.prototype.partition = function(pred) {
  let passed = []
  let failed = []
  for(let i = 0; i < this.length; i++) {
    if (pred(this[i])) {
      passed.push(this[i])
    } else {
     failed.push(this[i])
   }
  }
  return [ passed, failed ]
}