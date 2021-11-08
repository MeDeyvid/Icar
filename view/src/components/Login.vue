<template>
 <div class="divContent">
  <h1>Sistema de usuários</h1>

  <form id="form">

    <!--Usuário-->
    <div class="form-group row">
      <label for="user" class="col-sm-2 col-form-label">Usuário</label>
      <div class="col-sm-10">
        <input
          name="usuario"
          v-validade="{required: true}" 
          v-model="form.user"
          type="text"
          class="form-control">
      </div>
    </div>

    <!--Senha-->
    <div class="form-group row">
      <label for="passwd" class="col-sm-2 col-form-label">Password</label>
      <div class="col-sm-10">
        <input 
          name="senha"
          v-validade="{required: true}"
          v-model="form.passwd"
          type="password"
          class="form-control">
      </div>
    </div>

    <input @click.prevent="onsubmit" type="submit" id="btnEntrar" class="btn btn-dark" value="Entrar">

  </form>

 </div>
</template>

<script>

  export default {
    
    data() {
      return {
        form: {
          user: "",
          passwd: "",
        }
      }
    },

    methods: {
      onsubmit(){
        console.log(this.form.user);
        console.log(this.form.passwd);
        var vm = this;
        this.$http.post('php/login.php', this.usuario)
          .then(response => {
            localStorage.setItem('token', response.data);
            vm.$router.push({name: 'home'});
          })
          .catch(erro => {
            if(erro.request.status == '401') {
              this.mensagemErro = "Login e senha incorretos !!";
            }
          },
          this.$router.push({name: 'login'})
          );
      }
    }
  }
</script>

<style scoped>

  .divContent {
    width: 80%;
    background-color: #603F8B;
    margin: 10rem auto;
    padding: 2rem;
    border-radius: 4px;
    box-shadow: 10px 20px 15px #27222b;
  }

  .divContent h1 {
    font-size: 1.75rem;
    font-weight: 600;
    text-align: center;
    margin-bottom: 10px;
  }

  .registro span {
    margin-top: 10px;
  }
</style>