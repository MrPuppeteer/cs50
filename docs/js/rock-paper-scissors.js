const rock = document.querySelector('#rock');
const paper = document.querySelector('#paper');
const scissors = document.querySelector('#scissors');
const feedback1 = document.querySelector('#feed2');
const feedback2 = document.querySelector('#feed3');
const resetButton = document.querySelector('#resetButton');

function computerPlay() {
    const randomMove = Math.ceil(Math.random() * 3);
    if (randomMove === 1) {
        return "rock"
    } else if (randomMove === 2) {
        return "paper"
    } else { return "scissors" }
}

function play(plSelect, cpSelect) {
    if (plSelect === "rock" && cpSelect === "rock" || plSelect === "paper" && cpSelect === "paper" || plSelect === "scissors" && cpSelect === "scissors") {
        return "Draw!"
    } else if (plSelect === "rock" && cpSelect === "scissors" || plSelect === "paper" && cpSelect === "rock" || plSelect === "scissors" && cpSelect === "paper") {
        return "Player win!"
    } else { return "Computer win!" }
}

function reset() {
    rock.classList.remove("border", "border-dark");
    paper.classList.remove("border", "border-dark");
    scissors.classList.remove("border", "border-dark");
}

function input(e) {
    reset();
    this.classList.add("border", "border-dark");
    computerSelection = computerPlay();
    const playgame = play(`${this.getAttribute('id')}`, computerSelection);
    feedback1.value = `computer chooses ${computerSelection}`;
    feedback2.value = playgame;
}

rock.addEventListener('click', input);
paper.addEventListener('click', input);
scissors.addEventListener('click', input);

resetButton.addEventListener('click', function (e) {
    reset();
    feedback1.value = "";
    feedback2.value = "";
});