"""Argument parser for app_run"""

import argparse
import threading
from app_run_config.functions_app_run import (
    api_preparing,
    api_run,
    r_api_run,
)


def argument_parser_for_app_run():
    """
    There are defined args to use by app_run.py
    based on functions in app_run_config/functions_app_run.py
    """
    parser = argparse.ArgumentParser(description="Project runner")
    parser.add_argument(
        "--install", action="store_true", help="install project requirements"
    )

    args = parser.parse_args()

    if args.install:
        threading.Thread(target=api_preparing).start()
    else:
        threading.Thread(target=r_api_run).start()
        threading.Thread(target=api_run).start()

