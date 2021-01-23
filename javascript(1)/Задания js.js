'use strict'
const unique = array => {
    let arr = [];
    for (let i in array) { 
        if (!arr.includes(array[i])) {
            arr.push(array[i])
        }

    }
    return arr

}

const result = unique([2, 1, 4, 1, 2]);
console.log(result);
///
'use strict'
const difference = (array2, array1) => {
    let arr = [];
    for (let i in array2) { 
        if (!array1.includes(array2[i])) {
            arr.push(array2[i])
        }

    }
    return arr

}

const array1 = ['Beijing', 'Kiev'];
const array2 = ['Kiev', 'London', 'Baghdad'];
const result = difference(array1, array2);
console.log(result);
// Результат: ['Beij

///
function deepClone(obj) {
 if(isPromitive(obj)) {
  return obj
 } else if (isArray(obj)) {
  return obj.map((val) => {
   return deepClone(val)
  })
 } else if (isObject(obj)) {
  let res = {}
  for (let k in obj) {
   res[k] = deepClone(obj[k])
  }
  return res
 }
}

/////
function shuffle(array) {
  array.sort(() => Math.random() - 0.5);
}

///
function checkPalindrome(word) {    
    let l = word.length;
    for (let i = 0; i < l / 2; i++) {
        if (word.charAt(i) !== word.charAt(l - 1 - i)) {
            return false;
        }
    }
    return true;
}