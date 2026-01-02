var elements=document.getElementById("Tab");
var tableBody=document.querySelector("#Tab tbody");
var mainBtn = document.getElementById("Btn");

function ajouter(){
  var input = document.getElementById("input").value;

  if (input === "") return;
if(mainBtn.value=== "Ajouter"){
  var newRow = document.createElement("tr");
  var cell1 = document.createElement("td");
  var cell2 = document.createElement("td");

  var textNode =document.createTextNode(input);
  cell1.appendChild(textNode);
  var Btnsup = document.createElement("button");
  Btnsup.textContent ="supprimer";
  cell2.appendChild(Btnsup);
  Btnsup.onclick =function(){
    supprimer(this);
  };
  newRow.appendChild(cell1);
  newRow.appendChild(cell2);
  newRow.onmouseover = survolLigne;
  elements.appendChild(newRow);

  document.getElementById("input").value="";
}else{
    rowSelect.cells[0].innerText = input ;
    mainBtn.value ="Ajouter";
    document.getElementById("input").value="";
}
  

}

function supprimer(Btn){
  var row =Btn.parentNode.parentNode;
  row.remove();
}

function survolLigne(){
  rowSelect = this;
  var textInRow =this.cells[0].innerText;
  document.getElementById("input").value=textInRow;

  document.getElementById("Btn").value = "Modifier";

  
}

var existingRows = tableBody.getElementsByTagName("tr");
for (var i = 0; i < existingRows.length; i++) {
  existingRows[i].onmouseover = survolLigne;
}