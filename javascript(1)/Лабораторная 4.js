function removeElement(array, item) {
    for (let i in array) {
        if (array[i] === item) {
            console.log(array.splice(i, 1))
        }
    }
    return array
}


const array = ['Kiev', 'Beijing', 'Lima', 'Saratov'];
removeElement(array, 'Lima'); // удалит 'Lima' из массива
removeElement(array, 'Berlin'); // не удалит ничего
console.log(array);




const array = [1, 2, 3, 4, 5, 6, 7];
removeElements(array, 5, 1, 6);
console.log(array);


///
const removeElements = (array, ...args) => {
    for (let i in array) {
        for (let j in args) {
            if (array[i] === args[j]) {
                array.splice(i, 1)
            }
        }
    }

    return array
}


const array = ['Lima', 'Berlin', 'Moscow'];
removeElements(array, 'Lima', 'Moscow');
console.log(array);