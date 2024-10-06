<script setup>
import { VNumberInput } from 'vuetify/labs/VNumberInput'
import { ref } from 'vue';
import axios from 'axios';
let phone = ref();
let formValid = ref(false)
async function Send() {
    let form = new FormData();
    form.append("number", phone.value);
    await axios.post("http://192.168.0.6:8000/api/send", { form }).then(res => {
        console.log(res)
    })
}
const Rules = {
    Required: v => !!v || 'Pole nie może być puste'
}
</script>
<template>
    <v-layout>
        <v-container>
            <v-row>
                <v-col>
                    <h2>Alerty</h2>
                </v-col>
            </v-row>
            <v-row>
                <v-col class="w-100">
                    <v-card max-width="344 text-center">

                        <v-sheet class="mx-auto" width="300">
                            <v-form v-model="formValid">
                                <v-number-input :rules="[Rules.Required]" label="Wpisz numer telefonu"
                                    v-model="phone"></v-number-input>
                                <v-btn :disabled="!formValid" class="mt-3 mb-5" @click="Send()">Wyślij</v-btn>
                            </v-form>
                        </v-sheet>
                    </v-card>

                </v-col>

            </v-row>
        </v-container>
    </v-layout>
</template>