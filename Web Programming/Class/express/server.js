const express = require('express')
const bodyParser = require('body-parser');
const app = express()
app.use(bodyParser.urlencoded({extended: true}));
const port = 3000

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/bmicalculator.html');
})

// app.get("/contact", (req, res) =>{
//     res.send("contact me at: i221749@nu.edu.pk");
// });

// app.get("/about", (req, res) =>{
//     res.send("My name is lalaleo");
// });


// app.get("/hobies", (req, res) =>{
//     res.send("<ul><li>gaming</li><li>gaming2</li><li>gaming3</li></ul>");
// });

app.post("/" , (req, res) => {

    var height = parseFloat(req.body.height);
    var weight = parseFloat(req.body.weight);
    height = height / 100;

    var bmi = weight / (height * height);

    console.log("BMI: " + bmi);

    res.send("Your BMI is " + bmi.toFixed(2));
});



app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})