<template>
    <v-container>
        <v-row>
            <v-col>
                <div class="boxed">
                    <h3>Polecenia</h3>
                    <draggable class="list-group" :list="list1" group="people" itemKey="name">
                        <template #item="{ element, index }">
                            <div class="list-group-item">
                                <div class="item">
                                    {{ element.name }}
                                </div>
                            </div>
                        </template>
                    </draggable>
                </div>
            </v-col>
        </v-row>
        <v-row>
            <v-col>
                <div class="boxed">
                    <h3>Program</h3>
                    <draggable class="list-group" :list="list2" group="people" itemKey="name">
                        <template #item="{ element, index }">
                            <div class="list-group-item">
                                <div class="item">
                                    {{ element.name }}
                                </div>
                            </div>
                        </template>
                    </draggable>
                </div>
            </v-col>
        </v-row>
        <div class="row">

        </div>
    </v-container>
</template>
<script>
import draggable from "vuedraggable";

export default {
    name: "two-lists",
    display: "Two Lists",
    order: 1,
    components: {
        draggable
    },
    data() {
        return {
            list1: [
                { name: "Wyślij powiadomenie na email", id: 1 },
                { name: "Wyślij powiadomenie na telefon", id: 2 },
                { name: "Ponów", id: 9 },
                { name: "Pomiń", id: 4 },
                { name: "Puste", id: 6 },
                { name: "Puste", id: 8 },
            ],
            list2: [
                { name: "Rozpocznij", id: 5 },
                { name: "Zakończ", id: 7 }
            ]
        };
    },
    methods: {
        add: function () {
            this.list.push({ name: "Juan" });
        },
        replace: function () {
            this.list = [{ name: "Edgard" }];
        },
        clone: function (el) {
            return {
                name: el.name + " cloned"
            };
        },
        log: function (evt) {
            window.console.log(evt);
        }
    }
};
</script>
<style scoped>
.boxed {
    border: 1px black solid;
    padding: 5px;
    text-align: center;
    font-size: large;
}

.list-group-item {
    border: 1px black solid;
    border-radius: 5px;
    padding: 5px;
    margin-bottom: 2px;
}
</style>