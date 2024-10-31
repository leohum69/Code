
var fortunes = [
    "An exciting opportunity lies ahead of you.",
    "Happiness will come to you in waves.",
    "Your kindness will lead to unexpected rewards.",
    "You will soon receive good news.",
    "A dream you have will soon become reality.",
    "You are on the path to greatness.",
    "Today is a great day to try something new.",
    "Your hard work will soon pay off.",
    "Unexpected support will come from a new friend.",
    "You will discover hidden talents in yourself.",
    "A small decision today will lead to big changes tomorrow.",
    "Your creativity will be your greatest strength today.",
    "The solution you've been looking for is on its way.",
    "Trust your instincts—they will lead you to success.",
    "A new adventure is just around the corner.",
    "You are about to experience a burst of inspiration.",
    "Someone close to you will bring joy into your life.",
    "Your perseverance will soon be rewarded.",
    "An unexpected surprise will bring a smile to your face.",
    "You will find peace in a simple moment today."
];

function displayFortune() {
    var fortuneDisplay = document.getElementById('fortune-display');
    var randomIndex = Math.floor(Math.random() * fortunes.length);
    // alert(Math.random())
    fortuneDisplay.textContent = fortunes[randomIndex];
}

document.addEventListener('DOMContentLoaded', () => {
    displayFortune();
});
