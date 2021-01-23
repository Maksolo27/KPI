const createUser = (n, c) =>{
	if (typeof n === 'string' && typeof c === 'string'){
	const obj = {name:'', city:''};
	obj.name = n;
	obj.city = c;
	return obj;
}
}
createUser('Maksym', 'Roma')


const arr = [{
	name:'Andrey',
	phone:'+3809764572',
},
{
	name:'Alexey',
	phone:'+38067547812',
},
{
	name:'Mathias',
	phone:'+38097547542',
}]
const findPhonebyName = (name) =>{
	if (typeof name === 'string'){
		for (let i in arr){
			val = arr[i]
			if (name === val.name){
				return val.phone
			}
		}
	}
}
findPhonebyName('Mathias')


const random = (max, min)=>{
	if(!min){return Math.floor(Math.random() * max) + 0;}
	else{return Math.floor(Math.random() * max) + min;}
}
random(5, 1)


let characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
const generateKey = (length, characters)=>{
	let res = '';
	let characterslenght = characters.lenght
	for (let i = 0; i < length; i++){
		res += characters.charAt(Math.floor(Math.random() * characterslenght))
	}
	return res;
}
console.log(generateKey(5, characters))

let characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';