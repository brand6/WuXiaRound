import pandas as pd


def DealWorkSheet(filePath, excel, shtName):
    df = pd.read_excel(excel, shtName, index_col=0)
    df.to_csv(filePath + "\\CSV\\" + shtName + ".csv")


def DealWorkbook(filePath, excelName):
    excel = pd.ExcelFile(filePath + excelName)
    for shtName in excel.sheet_names:
        if shtName[0] != "#":
            DealWorkSheet(filePath, excel, shtName)


DealWorkbook(r"E:\UnReal\Program\WuXiaRound\Excel\\", "武学技能.xlsm")
