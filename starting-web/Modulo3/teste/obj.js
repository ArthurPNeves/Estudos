let pessoa = {
    nome: 'joao',
    idade: 45,
    casado: true
};
let prop = "nome";
console.log(pessoa);
console.log(pessoa.nome);
console.log(pessoa[prop]);

pessoa.numeroDeFilhos = 2;
console.log (pessoa);

function criaPessoa(n, i, c, f){
    let p = { };
        p.nome = n;
        p.idade = i;
        p.casado = c;
        p.numeroDeFilhos = f;
        return p;
}   

let pessoa1 = criaPessoa("Arthur", 25, true, 0);
console.log(1, pessoa1);
