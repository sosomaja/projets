x = document.querySelector('#namer').addEventListener('click', function () {
    naame = document.querySelector('input').value;
    document.querySelector('#greet').innerHTML = `hello, ${naame}`;
})