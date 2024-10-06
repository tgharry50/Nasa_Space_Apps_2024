#  plumber.R
library(ggplot2)
library(gridExtra)
library(png)
library(jsonlite)
library(httr)
library(xml2)

#* Echo back the input
#* @param msg The message to echo
#* @get /echo
function(msg=""){
  list(msg = paste0("The message is: '", msg, "'"))
}

#* Plot a histogram
#* @serializer png
#* @get /plot
function(){
  library(ggplot2)  # Upewnij się, że biblioteka ggplot2 jest załadowana
  
  # Tworzenie wykresu
  plen <- ggplot(data=iris, aes(x=Petal.Length, y=Petal.Width)) +
    geom_point() +
    coord_flip()
  plen
  ggsave("./tak.png")
  print(plen)  # Wyświetl wykres w pliku
  dev.off()  # Zamknij urządzenie graficzne
  readPNG("C:/Users/rafal/ARGUP/R_serwer/tak.png") 

}

#* Send JSON file
#* @serializer json
#* @get /sendjson/<numer>
function(numer) {
  json_data <- fromJSON(paste("C:/Users/rafal/ARGUP/R_serwer/Data/json/df17",numer,".json",sep=""))
  
  # Odpowiedź w formacie JSON
  json_data
}


#* Send JSON file
#* @serializer json
#* @get /sensor_R
function() {
  # Definiowanie URL API
  url <- "http://192.168.0.3/sensors"
  
  # Wykonanie zapytania GET
  response <- POST(url)
  
  response_content <- content(response, as = "text", encoding = "UTF-8")
  
  
  json_data <- fromJSON(response_content)
  
  # Zapisanie danych do pliku JSON
  write_json(json_data, "sensor_data.json", pretty = TRUE)
  
  # Zwrot danych JSON jako odpowiedź API
  json_data
  
}

