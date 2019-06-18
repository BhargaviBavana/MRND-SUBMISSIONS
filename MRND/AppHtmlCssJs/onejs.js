console.log('start');

//const promise = new Promise( (resolve,reject)=>{
//   //debugger;
//   const data={
//     name:"abc",
//     email:"abc@abc.com"
//   };
//   setTimeout( ()=>{
//      console.log('in Promise');
//   },500);
//    reject(data);
//} );
//
//promise.then(data=>console.log(data))
//       .catch(err=>console.log('Error',err));



//const promise=new Promise((resolve,reject)=>{
//             resolve('done');
//});
//
//promise.then(data=>console.log(data));
//
//for(let i=0;i<10;i++){
//    console.log(i);
//}


//const promiseArray=[]
//for(let i=0;i<10;i++){
//    const newPromise=new Promise((resolve,reject)=>{
//               console.log('executing',i);
//               resolve(i);
//    });
//    newPromise.then(number=>console.log('done',number));
//    promiseArray.push(newPromise);
//}
//Promise.all(promiseArray).then(()=>console.log('finish'));
//

fetch('https://api.github.com/users/octact').then(response=>{
               const jsonResponse=response.json();
               jsonResponse.then(data=>{
               console.log(data);
               })
});

console.log("end");