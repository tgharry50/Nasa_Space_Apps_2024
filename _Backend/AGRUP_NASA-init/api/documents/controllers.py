"""Defining controllers"""

import os
import subprocess
import re

import requests
from django.http import HttpRequest, JsonResponse, HttpResponse
from http import HTTPStatus

from documents.models import Sensor
from documents.schemas import SensorIn, DocumentIn

import matplotlib.pyplot as plt
from io import BytesIO

def sensor_json_R(request):
    r_response = requests.get(f"http://localhost:8080/sensor_R")
    
    # Odbierz dane w formacie JSON
    data = r_response.json()

    # Wyodrębnij odpowiednie pola z danych JSON
    sensor_data = {
        'dirt': data.get('dirt', None),
        'rain': data.get('rain', None),
        'air': data.get('air', None),
        'sun': data.get('sun', None),
        'pressure': data.get('pressure', None),
        'temperature': data.get('temperature', None)
    }

    # Tworzenie instancji modelu Sensor z danymi
    sensor = Sensor(**sensor_data)

    # Walidacja danych
    try:
        sensor.full_clean()  # Walidacja danych
        sensor.save()  # Zapis danych do bazy
    except ValidationError as e:
        return JsonResponse({"errors": e.message_dict}, status=400)

    # Zwracanie wszystkich rekordów Sensor
    sensors = Sensor.objects.all()
    return JsonResponse(list(sensors.values()), safe=False)


def dane_gleb_json(request,id: int):
    r_response = requests.get(f"http://localhost:8080/sendjson/{id}")
    return JsonResponse(r_response.json(), safe=False)

def dane_gleb(request):
    msg = request.GET.get("msg", "")
    r_response = requests.get(f"http://localhost:8080/echo?msg={msg}")
    return JsonResponse(r_response.json())

def dane_gleb_wykres(request):
    r_response = requests.get("http://localhost:8080/plot")
    img = BytesIO(r_response.content)
    
    return HttpResponse(img.getvalue(), content_type="image/png")

def create_document_controller(payload: DocumentIn):
    """POST method"""
    document = payload.dict()
    
    alert_payload = {
        "number": payload.dict()["number"],
        "message": payload.dict()["message"]
    }
    
    # Wykonaj żądanie POST na adres 192.168.0.3/alert
    response = requests.post("http://192.168.0.3/alert", json=alert_payload)
    return document