'use strict';
const pipe = (...fns) => x => {
    for (let i in fns) {
        if (typeof fns[i] !== 'function') {
            throw new TypeError("Typeerror")
        }
        return fns.reduce((v, f) => f(v), x);
    }

}

const inc = x => ++x;
const twice = x => x * 2;
const cube = x => x ** 3;

const f = pipe(inc, twice, cube);
const x = f(5);
console.log(x);

