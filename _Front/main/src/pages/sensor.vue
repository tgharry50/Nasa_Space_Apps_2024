<script setup>
import { L } from 'leaflet';
import { onMounted } from 'vue';
onMounted(() => {
    var map = L.map('map').setView([51.505, -0.09], 13);
    L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
        maxZoom: 19,
        attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
    }).addTo(map);
})
</script>
<template>
    <v-layout>
        <v-container>
            <div id="map"></div>
        </v-container>
    </v-layout>
</template>
<style scoped>
#map {
    height: 400px;
}
</style>