function lol(){
    button.isdisable = true;
}

document.querySelectorAll('.btn').forEach((button) => {
    button.addEventListener('click',function(){
        if(button.id === "correct"){
            lol();
        }
    }
)})
