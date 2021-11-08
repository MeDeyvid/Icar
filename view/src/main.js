import Vue from 'vue'
import App from './App.vue'
import { BootstrapVue } from 'bootstrap-vue'
import { createPopper } from '@popperjs/core'

import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'

Vue.use(BootstrapVue);
Vue.use(createPopper);

Vue.config.productionTip = false;

new Vue({
  render: h => h(App),
}).$mount('#app');
