const maxNumForm = document.querySelector('#maxNumForm');
const maxNum = document.querySelector("#maxNum");
const guessForm = document.querySelector('#guessForm');
const guessInput = document.querySelector('#guessInput');
const feedback = document.querySelector('#feed1');
let targetNum = null;
let attempts = 0;

maxNumForm.addEventListener('submit', function (e) {
    e.preventDefault();
    guessInput.removeAttribute('disabled');
    let maximum = maxNum.value;
    targetNum = Math.ceil(Math.random() * maximum);
});

guessForm.addEventListener('submit', function (e) {
    e.preventDefault();
    attempts++;
    let guess = parseInt(guessInput.value);
    if (guess === targetNum) {
        feedback.value = `You got it! It took you ${attempts} guesses.`;
        guessInput.setAttribute('disabled', '');
        attempts = 0;
    } else {
        if (guess > targetNum) {
            feedback.value = "Too high! Enter a new guess.";
        } else {
            feedback.value = "Too low! Enter a new guess.";
        }
    }
});