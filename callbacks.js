// function func1(func2){
    
//     console.log("func1");
//     func2(func3)
// }

// function func2(func3){
//     console.log("func2");
//     func3()
// }

// function func3(){
//     var a = 4 + 8;
//     console.log("func3 : ",a)
// }

// func1(func2)



// var a =  async function(obj,callback){
    
//     var p = {name: 'name', age: 35}
//     obj.p = p
//     await setTimeout(function(){
//         console.log("waiting for three seconds");
//     }, 1000);
//     console.log("...................")

    
// }
// var b =  function(obj){
//     var q = {name: 'name2', age: 37}
//     obj.q = q
//     console.log("*******************")
// }
// var func = async function(){

//     var obj = {};
//     var ans  = await a(obj,b)
    
//     console.log(ans)

// }
// func()



var a =  async function(obj) {
    var p = {name: 'name', age: 35}
    obj.p = p
    // await timeout(3000);
    await timeout(3000).then((data)=>{
        console.log("inside then : ",data);
    })
    console.log("...................")
    b(obj)
   }
   var b =  function(obj) {
    var q = {name: 'name2', age: 37}
    obj.q = q
    console.log("*******************")
   }
   function timeout(ms) {
    return new Promise((resolve,reject) => 
     setTimeout(function(){
       console.log("waiting for three seconds");
       resolve("success");
    }, ms));
   }
   
   var func = async function(){
    var obj = {};
    await a(obj,b)
    console.log(obj)
   }
   func()

