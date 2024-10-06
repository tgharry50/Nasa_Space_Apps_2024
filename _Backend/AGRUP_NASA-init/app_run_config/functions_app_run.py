"""Functions for argument_parser_app_run.py"""

import os
import subprocess
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent


def api_preparing():
    """Crucial preparations for the API and Django operations"""
    subprocess.run(
        ["poetry", "env", "use", "3.12"],
        cwd=str(BASE_DIR / "api"),
        shell=True,
        check=False,
    )
    subprocess.run(
        ["poetry", "install"],
        cwd=str(BASE_DIR / "api"),
        shell=True,
        check=False,
    )
    subprocess.run(
        ["poetry", "run", "python", "manage.py", "makemigrations"],
        cwd=str(BASE_DIR / "api"),
        shell=True,
        check=False,
    )
    subprocess.run(
        ["poetry", "run", "python", "manage.py", "migrate"],
        cwd=str(BASE_DIR / "api"),
        shell=True,
        check=False,
    )


def api_run():
    """Running django server"""
    subprocess.run(
        ["poetry", "run", "python", "manage.py", "runserver", "0.0.0.0:8000"],
        cwd=str(BASE_DIR / "api"),
        shell=True,
        check=False,
    )

def r_api_run():
    subprocess.run(
        ["Rscript", "api.R"],
        cwd=str(BASE_DIR / "R_serwer"),
        shell=True,
        check=False,
    )
