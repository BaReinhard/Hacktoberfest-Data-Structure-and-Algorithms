'use strict';

// 1
mediator.weather = 'rainy';
mediator.subscribe('weather:change', function (arg) {
  console.log(this.weather);
  this.weather = arg;
  console.log(this.weather);
});

mediator.publish('weather:change', 'sunny');

// 2
var person = {
  firstName: 'John',
  lastName: 'Doe'
};

mediator.bindTo(person);

person.subscribe('name:change', function (arg) {
  console.log(this.firstName);
  this.firstName = arg;
  console.log(this.firstName);
});

mediator.publish('name:change', 'Alex');
