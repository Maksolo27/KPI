'use strict'

function mySome(array, callbackfn) {
    if (array === null) {
        throw new TypeError('Массив равен null');
    }

    if (typeof callbackfn !== 'function') {
        throw new TypeError('Колбек должен быть функцией');
    }


    let t = array;
    let len = t.length;
    for (let i = 0; i < len; i++) {
        if (i in t && callbackfn(thisArg, t[i], i, t)) {
            return true;
        }
    }

    return false;
};
let arr = [3, 1, 2, 3, 13]
console.log(mysome(arr, x => x > 10))

'use strict';

const every = (array, callback) => {
    if (array === null) {
        throw new TypeError('Массив равен null!');
    }
    const len = array.length;
    if (typeof callback !== 'function') {
        throw new TypeError('Колбек должен быть функцией!');
    }
    let k = 0;
    while (k < len) {
        let value = array[k];
        const testResult = callback(value, k, array);
        if (!testResult) return false;
        k++;
    }
    return true;
};
