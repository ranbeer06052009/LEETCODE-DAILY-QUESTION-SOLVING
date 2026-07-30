/**
 * @return {Function}
 */
var createHelloWorld = function() {
    //const create="Hello World";
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */