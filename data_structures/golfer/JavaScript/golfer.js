class Golfer extends Person {
	constructor(handicap, name, age, gender) {
		super(name, age, gender);
		this.handicap = handicap;
	}

	printInfo() {
		console.log('Name: ' + this.name);
		console.log('Age: ' + this.age);
		console.log('Gender: ' + this.gender);
		console.log('Handicap: ' + this.handicap);
	}
}

class Person {
	constructor(name, age, gender) {
		this.name = name;
		this.age = age;
		this.gender = gender;
	}

	printInfo() {
		console.log('Name: ' + this.name);
		console.log('Age: ' + this.age);
		console.log('Gender: ' + this.gender);
	}
}