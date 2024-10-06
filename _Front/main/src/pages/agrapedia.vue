<script setup>
import { ref } from 'vue';

let tab = ref("one")
</script>
<template>
    <v-container>
        <v-img :width="200" aspect-ratio="1/1" cover src="../../public/agro.png"></v-img>
        <v-divider></v-divider>
        <v-card>
            <v-tabs v-model="tab" bg-color="primary">
                <v-tab value="one">Rodzaje zbóż</v-tab>
                <v-tab value="two">Rodzaje ulew</v-tab>
                <v-tab value="three">Rodzaje gleb</v-tab>
            </v-tabs>

            <v-card-text>
                <v-tabs-window v-model="tab">
                    <v-tabs-window-item value="one">
                        <v-row>
                            <v-col>
                                <b> Zboża, rośliny zbożowe </b>– grupa roślin uprawnych z rodziny wiechlinowatych (traw,
                                Poaceae). Ich owoce, o wysokiej zawartości skrobi, są wykorzystywane do celów
                                konsumpcyjnych, pastewnych i przemysłowych. Najpopularniejszymi produktami przerobu zbóż
                                są mąki, kasze, oleje i syropy. Zboża są podstawowym surowcem w wielu gałęziach
                                przemysłu takich jak: młynarstwo, piwowarstwo, gorzelnictwo, farmaceutyka.
                            </v-col>
                        </v-row>
                        <v-row>
                            <v-col>
                                <h2>Rodzaje zbóż:</h2>
                                <h3>Pszenica</h3>
                                <p>
                                    <b>Pszenica</b> występuje w formie jarej i ozimej. Jest zbożem o dużym znaczeniu
                                    gospodarczym, wykorzystywanym głównie do produkcji mąki. Pszenica ma wysokie
                                    wymagania
                                    glebowe i najlepiej rośnie na żyznych glebach. Termin siewu pszenicy ozimej przypada
                                    na
                                    II-III dekadę września, a jarej na III dekadę marca i I dekadę kwietnia. Zbiory
                                    odbywają się późnym latem.
                                </p>
                                <v-divider></v-divider>
                                <h3>Żyto</h3>
                                <p>
                                    <b>Żyto</b> również występuje w odmianie jarej i ozimej. Ma mniejsze wymagania
                                    glebowe niż
                                    pszenica. Żyto ozime wysiewa się w II-III dekadzie września, a jare w III dekadzie
                                    marca
                                    lub I dekadzie kwietnia. Zbiory przeprowadza się, gdy ziarno osiągnie wilgotność
                                    14-15%.
                                </p>
                                <v-divider></v-divider>
                                <h3>
                                    Jęczmień
                                </h3>
                                <p>
                                    W Polsce uprawia się głównie jęczmień jary, forma ozima jest mniej popularna ze
                                    względu
                                    na niską mrozoodporność. Jęczmień jary wysiewa się w drugiej połowie marca, a zbiory
                                    przeprowadza w sierpniu. Jest wykorzystywany m.in. w przemyśle browarniczym.
                                </p>
                                <v-divider></v-divider>
                                <h3>Owies</h3>
                                <p>
                                    <b>Owies</b> jest zbożem jarym, które można wysiewać najwcześniej ze wszystkich zbóż
                                    jarych.
                                    Termin siewu przypada między 15 marca a 10 kwietnia. Zbiory owsa odbywają się od
                                    III
                                    dekady lipca do II dekady sierpnia5. Owies ma właściwości fitosanitarne i stanowi
                                    dobry
                                    przedplon dla innych zbóż.
                                </p>
                                <v-divider></v-divider>
                                <h3>Pszenżyto</h3>
                                <p>
                                    Jest to zboże powstałe ze skrzyżowania pszenicy i żyta. Łączy w sobie cechy obu tych
                                    zbóż. Występuje w odmianach jarych i ozimych.
                                </p>
                                <v-divider></v-divider>
                                <h3>Kukurydza</h3>
                                <p>
                                    <b>Kukurydza</b> jest zbożem o wszechstronnym zastosowaniu - spożywczym, paszowym i
                                    przemysłowym. Jest bogata w składniki odżywcze i ma szerokie zastosowanie w
                                    gastronomii.
                                </p>
                            </v-col>
                        </v-row>
                    </v-tabs-window-item>

                    <v-tabs-window-item value="two">
                        <v-row>
                            <v-col>
                                <b>Ulewa</b> to opad deszczu o znacznym natężeniu, przekraczającym 12 mm na godzinę.
                                Jest to
                                zjawisko pogodowe, które może powodować lokalne podtopienia i utrudnienia w codziennym
                                funkcjonowaniu.
                            </v-col>
                        </v-row>
                        <v-row>
                            <v-col>
                                <h3>Rodzaje ulewy</h3>
                                <p>
                                    Według klasyfikacji opadów, możemy wyróżnić następujące rodzaje ulewy:
                                </p>
                                <p>
                                    - Deszcz ulewny I - natężenie opadu wynosi 0,2-0,6 mm/min lub 12,0-36,0 mm/h1.
                                </p>
                                <p>
                                    - Deszcz ulewny II - natężenie opadu wynosi 0,6-1,0 mm/min lub 36,0-60,0 mm/h1.
                                </p>
                                <p>
                                    - Deszcz ulewny III - natężenie opadu wynosi 0,1-1,4 mm/min lub 60,0-84,0 mm/h1.
                                </p>
                                <p>
                                    - Ulewa - natężenie opadu wynosi 1,4-1,9 mm/min lub 84,0-114,0 mm/h1.
                                </p>
                                <p>
                                    - Ulewa silna - natężenie opadu wynosi 1,9-2,9 mm/min lub 114,0-174,0 mm/h1.
                                </p>
                                <v-divider></v-divider>
                                <h3>
                                    Inne intensywne opady
                                </h3>
                                <p>
                                    Oprócz wymienionych rodzajów ulewy, istnieją jeszcze bardziej intensywne opady:
                                </p>
                                <p>
                                    Deszcz nawalny I i II - natężenie opadu przekracza 174,0 mm/h1.
                                </p>
                                <p>
                                    Nawałnica - natężenie opadu wynosi 234,0-414,0 mm/h1.
                                </p>
                                Nawałnica o charakterze klęski żywiołowej - natężenie opadu przekracza 414,0 mm/h1.
                                <h3>
                                    Skutki ulewy
                                </h3>
                                <v-divider></v-divider>
                                <p>
                                    - Intensywne opady deszczu mogą prowadzić do:
                                </p>
                                <p>
                                    - Lokalnych podtopień
                                </p>
                                <p>
                                    - Utrudnień w ruchu drogowym
                                </p>
                                <p>
                                    - Uszkodzeń infrastruktury
                                </p>
                                <p>
                                    - Zagrożenia powodziowego (przy opadach przekraczających 30 mm na dobę)
                                </p>
                            </v-col>
                        </v-row>
                    </v-tabs-window-item>

                    <v-tabs-window-item value="three">
                        <v-row>
                            <v-col>
                                <p>
                                    <b>Gleba</b> to biologicznie czynna, trójfazowa warstwa skorupy ziemskiej, która
                                    powstaje w
                                    wyniku procesów glebotwórczych1. Jest to złożona struktura składająca się z:
                                </p>
                                <p>
                                    - Części mineralnej
                                </p>
                                <p>
                                    - Części organicznej
                                </p>
                                <p>
                                    - Wody
                                </p>
                                <p>
                                    - Powietrza
                                </p>
                                <p>
                                    - Organizmów żywych
                                </p>
                                <p>
                                    Gleba tworzy się w wyniku oddziaływania klimatu, organizmów żywych, rzeźby terenu i
                                    działalności człowieka na skałę macierzystą w określonym czasie.
                                </p>
                                <p>
                                    Typowa gleba składa się z kilku warstw:
                                </p>
                                <p>
                                    Warstwa powierzchniowa z nierozłożonymi szczątkami organicznymi
                                </p>
                                <p>
                                    Warstwa próchnicy
                                </p>
                                <p>
                                    Warstwa wymywania
                                </p>
                                <p>
                                    Warstwa wmywania
                                </p>
                                <p>
                                    Warstwa skały macierzystej
                                </p>
                                <v-divider></v-divider>
                                <p>
                                    W Polsce występuje kilka głównych typów gleb:
                                </p>
                                <p>
                                    - Gleby brunatne i płowe - stanowią ponad 50% gleb w Polsce. Są to gleby średniej
                                    jakości,
                                    powstające w warunkach lasu liściastego.
                                </p>
                                <p>
                                    - Gleby bielicowe - zajmują około 26% powierzchni kraju. Są to gleby słabej jakości,
                                    tworzące się w warunkach lasu szpilkowego, głównie na terenach piaszczystych.
                                </p>
                                <p>
                                    - Czarnoziemy - najlepsze gleby rolnicze, ale stanowią tylko około 1% powierzchni
                                    Polski.
                                    Występują głównie na Wyżynie Lubelskiej, Wyżynie Małopolskiej i Płaskowyżu
                                    Głubczyckim.
                                </p>
                                <p>
                                    - Mady rzeczne - bardzo dobre gleby, zajmujące około 5% powierzchni kraju. Występują
                                    głównie w dolinach rzek, np. w delcie Wisły.
                                </p>
                                <p>
                                    - Czarne ziemie - gleby wysokiej jakości, stanowiące około 1% powierzchni Polski.
                                    Występują głównie na Kujawach.
                                </p>
                                <p>
                                    - Rędziny - gleby o dobrej jakości, stanowiące około 1% powierzchni kraju. Występują
                                    na
                                    Wyżynie Małopolskiej i Wyżynie Lubelskiej.
                                </p>
                                <p>
                                    - Gleby bagienne - zajmują około 7% powierzchni Polski, występują głównie na
                                    Podlasiu,
                                    Polesiu i pojezierzach.
                                </p>
                            </v-col>
                        </v-row>
                    </v-tabs-window-item>
                </v-tabs-window>
            </v-card-text>
        </v-card>
    </v-container>
</template>