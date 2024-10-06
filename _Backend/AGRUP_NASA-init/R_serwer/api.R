library(plumber)
# setwd("../ARGUP/R_serwer")

# Załaduj plik plumber.R
r <- plumb("test_api.R")

# Uruchom serwer API na porcie 8000
r$run(port = 8080)

