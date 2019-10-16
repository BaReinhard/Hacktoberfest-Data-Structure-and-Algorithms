function dayOfTheWeek(y, m, d) {
    const t = [0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4]
    y -= m < 3;
    return (y + Math.floor(y/4) - Math.floor(y/100) + Math.floor(y/400) + t[m-1] + d) % 7;
}

const dayMapping = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']

const tests = [
    [1886, 5, 1],
    [1948, 12, 10],
    [2001, 1, 15],
    [2017, 10, 10],
    [2018, 1, 1],
    [2018, 2, 16],
    [2018, 5, 17],
]

tests.forEach(test => console.log(test.join('/') + ': ' + dayMapping[dayOfTheWeek(...test)]))
