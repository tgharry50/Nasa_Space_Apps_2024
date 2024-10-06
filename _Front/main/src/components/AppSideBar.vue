<script setup>
let drawer = null
import { useRouter } from 'vue-router'
const router = useRouter();

</script>
<template>
    <v-navigation-drawer :clipped="true" :mobile-breakpoint="0">
        <v-list>
            <v-list-item>
                <v-list-item @click="router.push('/')" title="Strona główna">
                    <template v-slot:prepend><v-icon icon="mdi-home"></v-icon></template>
                </v-list-item>
                <v-list-item @click="router.push('/automatisation')" title="Automatyzacja">
                    <template v-slot:prepend><v-icon icon="mdi mdi-state-machine"></v-icon></template>
                </v-list-item>
                <v-list-item @click="router.push('/wykresy')" title="Statystyki">
                    <template v-slot:prepend><v-icon icon="mdi mdi-chart-bar"></v-icon></template>
                </v-list-item>
                <v-list-item @click="router.push('/lora')" title="Informacja z czujników">
                    <template v-slot:prepend><v-icon icon="mdi mdi-information"></v-icon></template>
                </v-list-item>
                <v-list-item @click="router.push('/sensor')" title="Czujniki">
                    <template v-slot:prepend><v-icon icon="mdi mdi-access-point-network"></v-icon></template>
                </v-list-item>
                <v-list-item @click="router.push('/alerts')" title="Alerty">
                    <template v-slot:prepend><v-icon icon="mdi mdi-alert-octagram-outline"></v-icon></template>
                </v-list-item>
            </v-list-item>
        </v-list>
    </v-navigation-drawer>
</template>