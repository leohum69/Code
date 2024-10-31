let x=0;
function hello(){
    alert("Helloworld");
}
function cont(){
    x++;
    // alert(x);
    document.querySelector('h2').innerHTML = x;
    if(x%10 === 0){
        alert(`counter is now ${x}`)
    }

}
function headi(){
    let hehe = document.querySelector('h1');
    if(hehe.innerHTML === "pewpew")
        hehe.innerHTML = "Hello World";
    else
        hehe.innerHTML = "pewpew";
}
document.addEventListener("DOMContentLoaded",function(){
    document.querySelector('button').onclick = cont;
    document.querySelector('form').onsubmit = function(){
        alert(`Hello, ${document.querySelector('#name').value}! How are you?`);
    }
});
