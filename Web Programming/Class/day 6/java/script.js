//generate table

function gentable(form){

    var amount;
    var rate;
    var years;
    var interest;
    var table;

    amount = document.getElementById("deposit").valueAsNumber;
    // alert(amount);
    rate = document.getElementById("rate").valueAsNumber;
    // alert(rate);
    years = document.getElementById("year").valueAsNumber;

    // alert(years);
    table = "<table><tr><th>Years</th><th>Starting Amount</th><th>Interest Earned</th><th>Ending Amount</th><tr/>"; 
    let i = 1;
    while(years>=i){
        table += "<tr>"
        table += "<td>" + i + "</td>";
        table += "<td>" + amount.toFixed(2) + "</td>";
        interest = amount * rate / 100;
        table += "<td>" + interest.toFixed(2) + "</td>";
        amount += interest;
        table += "<td>" + amount.toFixed(2) + "</td>";
        table += "</tr>"
        i++;
    }
    table += "</table>";

    document.getElementById("res").innerHTML = table;
}  

function clrchange(){
    let xd = document.getElementById("hehe").value;

    document.querySelector("h4").style.color = xd;
    document.querySelector('body').style.backgroundColor = xd;
}
