<script setup>
import { ref, onMounted } from 'vue'
import axios from 'axios';
import { useRouter } from 'vue-router'
const router = useRouter();
// 
import { Bar } from 'vue-chartjs'
import { Chart as ChartJS, Title, Tooltip, Legend, BarElement, CategoryScale, LinearScale } from 'chart.js'
//
ChartJS.register(Title, Tooltip, Legend, BarElement, CategoryScale, LinearScale);
const chartOptions = ref({
    responsive: true,
    maintainAspectRatio: false
});
let air = ref([]); let dirt = ref([]); let pressure = ref([]);
let rain = ref([]); let sun = ref([]); let temperatur = ref([]);



async function FetchLora() {
    setInterval(async () => {
        try {
            await axios.post("http://192.168.0.3:80/sensors").then(res => {
                if (air.value.length < 8) {
                    air.value.push((res.data.air).toFixed(2));
                    dirt.value.push((res.data.dirt).toFixed(2));
                    pressure.value.push(Math.ceil(res.data.pressure / 100));
                    rain.value.push((res.data.rain).toFixed(2));
                    sun.value.push((res.data.sun).toFixed(2));
                    temperatur.value.push((res.data.temperature).toFixed(2));

                } else {
                    air.value.shift();
                    air.value.push((res.data.air).toFixed(2));
                    dirt.value.shift();
                    dirt.value.push((res.data.dirt).toFixed(2));
                    pressure.value.shift();
                    pressure.value.push(Math.ceil(res.data.pressure / 100));
                    rain.value.shift();
                    rain.value.push((res.data.rain).toFixed(2));
                    sun.value.shift();
                    sun.value.push((res.data.sun).toFixed(2));
                    temperatur.value.shift();
                    temperatur.value.push((res.data.temperature).toFixed(2));
                }
            })
        } catch (err) {
            console.log(err)
        }
    }, 10000);
}
onMounted(() => FetchLora())
</script>

<template>
    <v-layout>
        <v-container>
            <v-row>
                <v-col>
                    <v-card class="mx-auto text-center" color="blue" max-width="600" dark>
                        <v-card-text>
                            <v-sheet color="rgba(0, 0, 0, .12)">
                                <v-sparkline :color="'rgba(255, 255, 255, .7)'" :fill="true" :line-width="1"
                                    :model-value="air" :smooth="false" auto-draw>
                                    <template v-slot:label="item"> {{ item.value }} </template>
                                </v-sparkline>
                            </v-sheet>
                        </v-card-text>
                        <v-card-text>
                            <div class="text-h4 font-weight-thin">Jakosc Powietrza</div>
                        </v-card-text>
                    </v-card>
                </v-col>
                <v-col>
                    <v-card class="mx-auto text-center" color="blue" max-width="600" dark>
                        <v-card-text>
                            <v-sheet color="rgba(0, 0, 0, .12)">
                                <v-sparkline :color="'rgba(255, 255, 255, .7)'" :fill="true" :line-width="1"
                                    :model-value="dirt" :smooth="false" auto-draw>
                                    <template v-slot:label="item"> {{ item.value }} </template>
                                </v-sparkline>
                            </v-sheet>
                        </v-card-text>
                        <v-card-text>
                            <div class="text-h4 font-weight-thin">Wilgotnosc Gleby</div>
                        </v-card-text>
                    </v-card>
                </v-col>
            </v-row>
            <v-row>
                <v-col>
                    <v-card class="mx-auto text-center" color="blue" max-width="600" dark>
                        <v-card-text>
                            <v-sheet color="rgba(0, 0, 0, .12)">
                                <v-sparkline :color="'rgba(255, 255, 255, .7)'" :fill="true" :line-width="1"
                                    :model-value="pressure" :smooth="false" auto-draw>
                                    <template v-slot:label="item"> {{ item.value }} </template>
                                </v-sparkline>
                            </v-sheet>
                        </v-card-text>
                        <v-card-text>
                            <div class="text-h4 font-weight-thin">Cisnienie [hPs]</div>
                        </v-card-text>
                    </v-card>
                </v-col>
                <v-col>
                    <v-card class="mx-auto text-center" color="blue" max-width="600" dark>
                        <v-card-text>
                            <v-sheet color="rgba(0, 0, 0, .12)">
                                <v-sparkline :color="'rgba(255, 255, 255, .7)'" :fill="true" :line-width="1"
                                    :model-value="rain" :smooth="false" auto-draw>
                                    <template v-slot:label="item"> {{ item.value }} </template>
                                </v-sparkline>
                            </v-sheet>
                        </v-card-text>
                        <v-card-text>
                            <div class="text-h4 font-weight-thin">Opady</div>
                        </v-card-text>
                    </v-card>
                </v-col>
            </v-row>
            <v-row>
                <v-col>
                    <v-card class="mx-auto text-center" color="blue" max-width="600" dark>
                        <v-card-text>
                            <v-sheet color="rgba(0, 0, 0, .12)">
                                <v-sparkline :color="'rgba(255, 255, 255, .7)'" :fill="true" :line-width="1"
                                    :model-value="sun" :smooth="false" auto-draw>
                                    <template v-slot:label="item"> {{ item.value }} </template>
                                </v-sparkline>
                            </v-sheet>
                        </v-card-text>
                        <v-card-text>
                            <div class="text-h4 font-weight-thin">Naslonecznienie</div>
                        </v-card-text>
                    </v-card>
                </v-col>
                <v-col>
                    <v-card class="mx-auto text-center" color="blue" max-width="600" dark>
                        <v-card-text>
                            <v-sheet color="rgba(0, 0, 0, .12)">
                                <v-sparkline :color="'rgba(255, 255, 255, .7)'" :fill="true" :line-width="1"
                                    :model-value="temperatur" :smooth="false" auto-draw>
                                    <template v-slot:label="item"> {{ item.value }} </template>
                                </v-sparkline>
                            </v-sheet>
                        </v-card-text>
                        <v-card-text>
                            <div class="text-h4 font-weight-thin">Temperatura [C]</div>
                        </v-card-text>
                    </v-card>
                </v-col>
            </v-row>
        </v-container>
    </v-layout>
</template>