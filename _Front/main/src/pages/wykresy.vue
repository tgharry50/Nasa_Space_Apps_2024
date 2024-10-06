<script setup>
import { ref, watch } from 'vue'
import { useRouter } from 'vue-router'
import axios from 'axios'
const router = useRouter();
let data = ref();
let search = ref()
async function FetchDraft(value) {
    await axios.get(`http://192.168.0.6:8000/api/sendjson2/${value}`).then(res => {
        data.value = res.data
    })
}
let items = [
    { key: 'Ogólnopolska', value: 1 }, { key: 'Dolnośląska', value: 2 },
    { key: 'Kujawsko-Pomorskie', value: 3 }, { key: 'Lubelskie', value: 4 },
    { key: 'Lubuskie', value: 5 }, { key: 'Łódzkie', value: 6 },
    { key: 'Małopolskie', value: 7 }, { key: 'Mazowieckie', value: 8 },
    { key: 'Opolskie', value: 9 }, { key: 'Podkarpackie', value: 10 },
    { key: 'Podlaskie', value: 11 }, { key: 'Pomorskie', value: 12 },
    { key: 'Śląskie', value: 13 }, { key: 'Świętokrzyskie', value: 14 },
    { key: 'Warmińsko-Mazurskie', value: 15 }, { key: 'Wielkopolskie', value: 16 },
    { key: 'Zachodniopomorskie', value: 17 },
]
watch(search, async (value) => {
    await FetchDraft(value);
})
</script>
<template>
    <v-layout>
        <v-container>
            <v-row>
                <v-col>
                    <v-autocomplete :items="items" :item-title="'key'" :item-value="'value'" label="Wybierz region"
                        v-model="search">
                    </v-autocomplete>

                </v-col>
            </v-row>
            <v-row>
                <v-col>
                    <v-data-table :items="data" item-key="X" :headers="[
                        { title: 'Zbiór danych', value: 'X', key: 'X', align: 'start' },
                        { title: 'Plony', value: 'Plony', key: 'Plony', align: 'start' },
                        { title: 'Plony z hektara ziemi', value: 'Plony.z.1.ha.w.dt', key: 'Plony.z.1.ha.w.dt', align: 'start' },
                        { title: 'Powierzchnia', value: 'Powierzchnia', key: 'Powierzchnia', align: 'start' },
                        { title: 'Powierzchnia w hektarach', value: 'Powierzchnia.w.ha', key: 'Powierzchnia.w.ha', align: 'start', },
                        { title: 'Zbiory', value: 'Zbiory', key: 'Zbiory', align: 'start' },
                        { title: 'Zbiory w dt', value: 'Zbiory.w.dt', key: 'Zbiory.w.dt', align: 'start' }
                    ]">

                    </v-data-table>
                </v-col>
            </v-row>
        </v-container>
    </v-layout>
</template>