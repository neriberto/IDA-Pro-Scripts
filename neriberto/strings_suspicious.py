#!/usr/bin/env python

"""strings_suspicious.py: Enumerate suspicious strings."""

__author__	= "Neriberto C.Prado"
__copyright__	= "Copyright 2015, Neriberto C.Prado"

from idaapi import *
from idc import *
from idautils import *
import ctypes
from PySide import QtGui, QtCore

# Disable Security
disable_security = [
    "antivirus",
    "antivirusproduct",
    "spywareproduct",
    "firewallproduct",
    "symantec",
    "kaspersky",
    "kasper~1",
    "mcafee",
    "avg.com",
    "grisoft",
    "avastui.exe",
    "avastsvc.exe",
    "aswchlic.exe",
    "ashupd.exe",
    "alwil software",
    "avast software",
    "vipre",
    "gfi",
    "sunbelt",
    "panda",
    "security",
    "eset",
    "nod32",
    "avira",
    "avp.exe",
    "windows defender",
    "winddefend",
    "wscsvc",
    "wuauserv",
    "bits",
    "ersvc",
    "wersvc",
    "trendmicro",
    "clamav",
    "clamd",
    "wireshark",
    "tcpview",
    "regmon",
    "procmon",
    "procexp",
    "mbsa",
    "filemon",
    "autoruns",
    "{fd6905ce-952f-41f1-9a6f-135d9c6622cc}",
    "hosts",
    ":\\windows\\system32\\drivers\\etc\\hosts",
    ":\\winnt\\system32\\drivers\\etc\\hosts",
    ":\\windows\\hosts",
    "\\drivers\\etc\\hosts"
]

# Brazilian Bankers
bbankers = [
    "gbplugin",
    "cef.gpc",
    "bb.gpc",
    "banerj",
    "bovespa",
    "mercantildobrasil",
    "boavista",
    "bonsucesso",
    "bradesco",
    "brascan",
    "cacique",
    "Cifra",
    "citibank",
    "citicard",
    "bancocnh",
    "cnhcapital",
    "Sudameris",
    "sicredi",
    "cruzeiro",
    "daycoval",
    "bandepe",
    "dibens",
    "bancobrasil",
    "bb.com.br",
    "bbseguroauto.com.br",
    "www.bep.com.br",
    "besc.com.br",
    "fator.com.br",
    "bancofiat",
    "ficsa",
    "fidis",
    "finasa",
    "bmc.com.br",
    "bmcnet",
    "bancoford",
    "fordcredit",
    "bancoguanabara",
    "bcoguan",
    "bancohonda",
    "unibanco",
    "investcred",
    "itau",
    "safra",
    "mercantil",
    "bancooriginal",
    "panamericano.com.br",
    "real.com.br",
    "bancoreal",
    "rodobens",
    "santander",
    "sofisa",
    "sumitomo",
    "bancotoyota",
    "bancovw",
    "vw.com.br",
    "bancovolkswagen",
    "bancovotorantim",
    "yamaha-motor",
    "banestes",
    "banif",
    "hipercard",
    "hsbc",
    "jpmorgan",
    "bancobva",
    "bancofibra",
    "caixa.com.br",
    "nossacaixa",
    "internetcaixa",
    "rendimento.com.br",
    "scotiabank",
    "rural.com.br",
    "unicard",
    "cielo",
    "serasa",
    "banespa",
    "mercantil",
    "bancoamazonia",
    "banparanet",
    "equifax",
    "lusobrasileiro"
]

terms = [
	'token',
    'login',
	'password',
	'username',
	'usuario',
	'senha',
	'agencia',
	'banco',
	'cartao',
	'simples',
	'proxy',
	'desconectado',
	'reconectar',
	'conex',
    'http',
    'fuck',
    "adobe",
    ".cpl",
    "premios",
    "promocao",
    "portal",
    "credencie",
    "cadastramento",
    "fatura",
    "sorteio"
]


class ByteStringsViewer_t(PluginForm):

    name = "Strings Suspicious"

    def Show(self):
        return PluginForm.Show(self,self.name,options = PluginForm.FORM_PERSIST)

    def OnCreate(self,form):
        self.parent = self.FormToPySideWidget(form)
        self.byte_strings = {}
        self.table = QtGui.QTableWidget()
        self.table.setRowCount(1)
        self.table.setColumnCount(3)
        #self.table.setHorizontalHeaderLabels(("Address","Function","String"))
        self.table.setHorizontalHeaderLabels(["Strings"])
        layout = QtGui.QVBoxLayout()
        layout.addWidget(self.table)
        self.clipboard = QtGui.QClipboard()
        self.Create()
        self.parent.setLayout(layout)

    def OnClose(self,form):
        global ByteStringForm
        del ByteStringForm

    def click_row(self):
        i = self.table.item(self.table.currentRow(),0)
        bstr = self.table.item(self.table.currentRow(),2)
        addr = i.text().strip()
        bstr = bstr.text()
        if not addr.startswith("0x"):
            addr = get_name_ea(BADADDR,str(addr))
        else:
            addr = addr[2:10]
            addr= int(addr,16)
        Jump(addr)
        self.clipboard.setText(bstr)
        return

    def Create(self):
        self.table.clear()
        self.table.setColumnCount(1)
        self.table.setHorizontalHeaderLabels(["Strings"])
        #self.table.setHorizontalHeaderLabels(("Address","Function","String"))
        #self.table.itemClicked.connect(self.click_row)
        self.find_byte_strings()
        self.table.setRowCount(len(self.byte_strings.keys()))
        row = 0
        for addr,bstr in self.byte_strings.items():
            #self.table.setItem(row,0,QtGui.QTableWidgetItem(addr))
            #self.table.setItem(row,1,QtGui.QTableWidgetItem(addr))
            self.table.setItem(row,0,QtGui.QTableWidgetItem(bstr))
            self.table.resizeRowToContents(row)
            row += 1
        self.table.setSortingEnabled(False)

    def find_byte_strings(self):
        global terms
        global bbankers
        global disable_security
        # Append Brazilian Bankers to terms
        terms += bbankers
        terms += disable_security
        count = 1
        for ss in Strings():
            s = str(ss)
            if s.lower() in terms:
                self.byte_strings[str(count)] = s
                count = count + 1

def find_all_byte_strings():
    global ByteStringForm
    ByteStringForm = ByteStringsViewer_t()
    ByteStringForm.Show()
    ByteStringForm.table.resizeRowsToContents()
    ByteStringForm.table.resizeColumnsToContents()


find_all_byte_strings()
