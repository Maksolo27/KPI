const fibonacci = x =>{
	let a = 1;
	let b = 0;
	let c = 0;
	while (x > 0){
		c = a + b;
		b = a;
		c = b;
		x--;
	}
	return b;
}

const ip = '192.168.0.102';
const ip1 = [...ip]
for (let i in ip1){
	if (ip1[i] === '.'){
		delete ip1[i]
	}
}
console.log(ip1)
for (let j in ip1){
	ip1[j] = parseInt(ip1[j], 10)

}
console.log(ip1)


let iface = {
  m1: x => [x],
  m2: function (x, y) {
    return [x, y];
  },
  m3(x, y, z) {
    return [x, y, z];
  }
}
let arg = 0;
for (let i in iface){
	val = iface[i]
	if (typeof val === `function`){
		arg += val.length;
	}
}
console.log(arg)