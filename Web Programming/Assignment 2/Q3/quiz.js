
const quizQuestions = [
    {
        question: "What is the capital of Missouri?",
        options: ["A) St. Louis", "B) Jefferson City", "C) Kansas City"],
        answer: "B"
    },
    {
        question: "How many ounces are in a pound?",
        options: ["A) 10", "B) 12", "C) 16"],
        answer: "C"
    },
    {
        question: "Who was the first person to set foot on the moon?",
        options: ["A) Buzz Aldrin", "B) Michael Collins", "C) Neil Armstrong"],
        answer: "C"
    },
    {
        question: "Who holds the MLB record for most home runs in a season?",
        options: ["A) Barry Bonds", "B) Hank Aaron", "C) Babe Ruth"],
        answer: "A"
    },
    {
        question: "In what year was the University of Liverpool founded?",
        options: ["A) 1250", "B) 1881", "C) 1970"],
        answer: "B"
    },
    {
        question: "What is the largest planet in our solar system?",
        options: ["A) Earth", "B) Jupiter", "C) Saturn"],
        answer: "B"
    },
    {
        question: "Who wrote 'Pride and Prejudice'?",
        options: ["A) Emily Brontë", "B) Charles Dickens", "C) Jane Austen"],
        answer: "C"
    },
    {
        question: "What is the square root of 64?",
        options: ["A) 6", "B) 8", "C) 10"],
        answer: "B"
    },
    {
        question: "What is the chemical symbol for water?",
        options: ["A) O2", "B) H2O", "C) CO2"],
        answer: "B"
    },
    {
        question: "Which country is home to the Great Wall?",
        options: ["A) China", "B) Japan", "C) Korea"],
        answer: "A"
    }
];

function startQuiz() {
    const numQuestions = parseInt(document.getElementById("num-questions").value);
    const quizContainer = document.getElementById("quiz-container");
    quizContainer.innerHTML = "";

    const selectedQuestions = shuffleArray(quizQuestions).slice(0, numQuestions);
    
    selectedQuestions.forEach((questionObj, index) => {
        const questionHTML = `
            <div class="question-block">
                <p>${index + 1}. ${questionObj.question}</p>
                <label><input type="radio" name="q${index}" value="A"> ${questionObj.options[0]}</label><br>
                <label><input type="radio" name="q${index}" value="B"> ${questionObj.options[1]}</label><br>
                <label><input type="radio" name="q${index}" value="C"> ${questionObj.options[2]}</label><br>
            </div>
        `;
        quizContainer.innerHTML += questionHTML;
    });

    quizContainer.innerHTML += `<button type="button" onclick="submitQuiz(${numQuestions})">Submit Quiz</button>`;
}

function shuffleArray(array) {
    return array.sort(() => Math.random() - 0.5);
}

function submitQuiz(numQuestions) {
    const quizContainer = document.getElementById("quiz-container");
    const resultContainer = document.getElementById("result-container");
    let correctCount = 0;
    resultContainer.innerHTML = ""; 

    quizQuestions.slice(0, numQuestions).forEach((questionObj, index) => {
        const userAnswer = document.querySelector(`input[name="q${index}"]:checked`);
        
        if (userAnswer) {
            const selectedAnswer = userAnswer.value;
            if (selectedAnswer === questionObj.answer) {
                correctCount++;
                resultContainer.innerHTML += `<p>${index + 1}. ${questionObj.question}<br>You guessed  ${questionObj.options[selectedAnswer.charCodeAt(0) - 65]}<br>CORRECT</p>`;
            } else {
                resultContainer.innerHTML += `<p>${index + 1}. ${questionObj.question}<br>You guessed  ${questionObj.options[selectedAnswer.charCodeAt(0) - 65]}<br>INCORRECT: the correct answer is  ${questionObj.options[questionObj.answer.charCodeAt(0) - 65]}</p>`;
            }
        } else {
            resultContainer.innerHTML += `<p>${index + 1}. ${questionObj.question}<br>You did not select an answer.<br>INCORRECT: the correct answer is ${questionObj.options[questionObj.answer.charCodeAt(0) - 65]}</p>`;
        }
    });

    const percentage = ((correctCount / numQuestions) * 100).toFixed(2);
    resultContainer.innerHTML += `<p>You answered ${correctCount} out of ${numQuestions} questions correctly (${percentage}%).</p>`;
}
