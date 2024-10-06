<script setup>
import { onMounted, onBeforeMount } from 'vue'
import { ref } from 'vue';
import axios from 'axios'
import 'leaflet/dist/leaflet.css';
let image = ref('/Clear.png')
function swap(value) {
  image.value = value;
}
</script>
<template>
  <v-container>
    <v-row>
      <v-col>
        <v-img :aspect-ratio="1" class="bg-white" :src="image" width="700" cover></v-img>
      </v-col>
      <v-col>
        <v-list>
          <v-list-item class="pb-1">
            <v-btn class="w-100" variant="flat" color="green" @click="swap('../public/Clear.png')">
              Oryginalne
            </v-btn>
          </v-list-item>
          <v-list-item class="pb-1">
            <v-btn class="w-100" variant="flat" color="green" @click="swap('../public/EVI.png')">
              EVI
            </v-btn>
          </v-list-item>
          <v-list-item class="pb-1">
            <v-btn class="w-100" variant="flat" color="green" @click="swap('../public/NDRE.png')">
              NDRE
            </v-btn>
          </v-list-item>
          <v-list-item class="pb-1">
            <v-btn class="w-100" variant="flat" color="green" @click="swap('../public/NDSI.png')">
              NDSI
            </v-btn>
          </v-list-item>
          <v-list-item class="pb-1">
            <v-btn class="w-100" variant="flat" color="green" @click="swap('../public/NDVI.png')">
              NDVI
            </v-btn>
          </v-list-item>
          <v-list-item class="pb-1">
            <v-btn class="w-100" variant="flat" color="green" @click="swap('../public/NDWI.png')">
              NDWI
            </v-btn>
          </v-list-item>
        </v-list>
      </v-col>
    </v-row>
  </v-container>
</template>
<style scoped>
#map {
  width: 60vw;
  height: 80vh;
}
</style>