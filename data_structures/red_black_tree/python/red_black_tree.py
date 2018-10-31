#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import os
import random


class Nodo:
    # True(1) para nodo black; False(0) para nodo red; (2) para nodo "double black".
    def __init__(self, item, black, esq = None, dir = None):
        self.item = item
        self.black = black
        self.esq = esq
        self.dir = dir

        
class ArvoreBinaria:
    # itensRecentes sao os nodos alterados/criados na última inserçao ou remoçao.
    # O primeiro elemento é o principal,
    # por ser ou o nodo inserido ou o substituto daquele que foi removido.
    def __init__(self, raiz = None):
        self.raiz = raiz
        if (raiz != None):
            self.itensRecentes = [raiz.item, None]
        else:
            self.itensRecentes = [None]
    # Nodo nodo
    def criarNodo(self, item, black):
        return Nodo(item, black)
    # Reseta os itensRecentes
    def clearRecentes(self):
        self.itensRecentes = [None]
    # Calcula a altura de nodos pretos somente,
    # a qual deve ser constante para os ramos esquerdos e direitos de uma árvore rubro-negra.
    def getAlturas(self, raiz):
        if (raiz == None): return 1,1
        altBlackEsq, altRedEsq = self.getAlturas(raiz.esq)
        altBlackDir, altRedDir = self.getAlturas(raiz.dir)
        return raiz.black + max(altBlackEsq, altBlackDir), not raiz.black + max(altRedEsq, altRedDir)
    # Calcula a diferença de altura de nodos pretos entre os ramos esquerdos e direitos
    def getBlackBalanco(self, raiz):
        if (raiz == None): return True
        altBlackEsq, altRedEsq = self.getAlturas(raiz.esq)
        altBlackDir, altRedDir = self.getAlturas(raiz.dir)
        return (altBlackEsq - altBlackDir == 0) and altRedEsq <= altBlackEsq and altRedDir <= altBlackDir
    # Calcula a altura total
    def getAltura(self, raiz):
        if (raiz == None): return 0
        return 1 + max(self.getAltura(raiz.esq), self.getAltura(raiz.dir))
    # Calcula o balanceamento total, o qual nao precisa estar tao preciso quanto a AVL.
    def getBalanco(self, raiz):
        if (raiz == None): return 0
        return self.getAltura(raiz.esq) - self.getAltura(raiz.dir)
    # Rotaciona à direita
    def rotacaoDir(self, velhaRaiz):
        novaRaiz = velhaRaiz.esq
        velhaRaiz.esq, novaRaiz.dir = novaRaiz.dir, velhaRaiz
        if (velhaRaiz.item == self.itensRecentes[0]):
            self.itensRecentes[0] = novaRaiz.item
        self.itensRecentes.extend([velhaRaiz.item, novaRaiz.item, velhaRaiz.esq])
        return novaRaiz
    # Rotaciona à esquerda
    def rotacaoEsq(self, velhaRaiz):
        novaRaiz = velhaRaiz.dir
        velhaRaiz.dir, novaRaiz.esq = novaRaiz.esq, velhaRaiz
        if (velhaRaiz.item == self.itensRecentes[0]):
            self.itensRecentes[0] = novaRaiz.item
        self.itensRecentes.extend([velhaRaiz.item, novaRaiz.item, velhaRaiz.dir])
        return novaRaiz
    # True se o nodo é black ou None, senao false
    # Nodos "None" sao sempre black
    def isNodoBlack(self, nodo):
        return (nodo.black if nodo != None else True)
    # True se o nodo é red, senao false
    def isNodoRed(self, nodo):
        return (not nodo.black if nodo != None else False)
    # Retorna o nodo com o atributo black modificado (padrao: True, ou Black)
    def setNodoToBlack(self, nodo, black = True):
        if (nodo != None and nodo.item != None):
            nodo.black = black
            self.itensRecentes.append(nodo.item)
            return nodo
        return
    # Retorna o nodo com o atributo black modificado (padrao: False, ou Red)
    def setNodoToRed(self, nodo, black = False):
        if (nodo != None and nodo.item != None):
            nodo.black = black
            self.itensRecentes.append(nodo.item)
            return nodo
        return
    # Retorna os dois nodos de entrada, com seus atributos black trocados
    def swapNodoCor(self, nodo1, nodo2): ######################
        nodo1_blackness = self.isNodoBlack(nodo1)
        nodo1 = self.setNodoToBlack(nodo1, black = self.isNodoBlack(nodo2))
        nodo2 = self.setNodoToBlack(nodo2, black = nodo1_blackness)
        self.itensRecentes.extend([nodo1.item, nodo2.item])
        return nodo1, nodo2
    # Inicializa a recursao da inserçao
    # Raiz sempre é BLACK.
    def inserir(self, item, raiz):
        raiz, caso = self.inserirMengo(item, raiz)
        raiz.black = True
        self.itensRecentes.append(None)
        return raiz
    # Inserçao binária recursiva comum, adicionada de balanceamento para a árvore rubro-negra
    # Sobre a variável "caso":
    # Se 0 significa que nao há mais nenhuma modificaçao necessária
    # Se 1 significa que o nodo atual(raiz) é o pai do nodo inserido
    # Se 2 significa que o nodo atual(raiz) é o avô do nodo inserido
    def inserirMengo(self, item, raiz):
        if (raiz == None): # O item nao existe, logo um nodo correspondente é criado. Sempre RED.
            nodo = self.criarNodo(item, False)
            self.itensRecentes = [item]
            return nodo, 1
        if (item < raiz.item): # Recursa para o ramo esquerdo
            raiz.esq, caso = self.inserirMengo(item, raiz.esq)
            tio = raiz.dir
        elif (item > raiz.item): # Recursa para o ramo direito
            raiz.dir, caso = self.inserirMengo(item, raiz.dir)
            tio = raiz.esq
        else: # Item repetido, logo Caso = 0
            self.itensRecentes = []
            return raiz, 0
        
        if (caso == 1):
            if (raiz.black): # Se o pai é preto, nao precisa modificar mais nada.
                caso = 0
            else: # Senao, vai depender do tio, logo deve-se retornar ao avô.
                caso = 2
        elif (caso == 2):
            if (self.isNodoBlack(tio)): # Se o tio é preto, a operaçao é similar a da árvore AVL
                balanco = self.getBalanco(raiz)
                if (balanco > 1): # Desbalanceada para à esquerda
                    if (item > raiz.esq.item): #Left-Right, senao Left-Left
                        raiz.esq = self.rotacaoEsq(raiz.esq)
                    raiz = self.rotacaoDir(raiz)
                    raiz.dir, raiz = self.swapNodoCor(raiz.dir, raiz) # A diferença para à AVL está nesse troca de cor entre raiz e tio
                    caso = 0 # Ao fim, nao é necessária mais nenhuma modificaçao
                elif (balanco < -1): # Desbalanceada para à direita
                    if (item < raiz.dir.item): #Right-Left, senao Right-Right
                        raiz.dir = self.rotacaoDir(raiz.dir)
                    raiz = self.rotacaoEsq(raiz)
                    raiz.esq, raiz = self.swapNodoCor(raiz.esq, raiz) # A diferença para à AVL está nesse troca de cor entre raiz e tio
                    caso = 0 # Ao fim, nao é necessária mais nenhuma modificaçao
            else: # Se o tio é vermelho, deve-se pintar pai e tio de preto, o avô de vermelho, e considerar o avô como o novo filho
                raiz.esq = self.setNodoToBlack(raiz.esq)
                raiz.dir = self.setNodoToBlack(raiz.dir)
                raiz = self.setNodoToRed(raiz)
                caso = 1 # Avô (nodo atual) vira filho.
        return raiz, caso
    # Retorna o nodo com o atributo black = 2
    # É um nodo especial para ser usado, temporariamente, no processo de remoçao
    def setNodoToDoubleBlack(self, nodo):
        if (nodo == None): return self.criarNodo(None, 2)
        nodo.black = 2
        self.itensRecentes.append(nodo.item)
        return nodo
    # Testa se o nodo é "double black", ou black = 2
    def isNodoDoubleBlack(self, nodo):
        return (nodo.black == 2 if nodo != None else False)
    # Funçao auxiliar da remocao
    # Retorna o maior nodo no ramo esquerdo
    def delNodoSubstituto(self, nodo):
        if (nodo.dir != None): return self.delNodoSubstituto(nodo.dir)
        return nodo
    # Inicializa a recursao da remoçao
    # Raiz sempre é BLACK
    def deletar(self, item, raiz):
        if (raiz == None): return
        self.itensRecentes = []
        itemAtual = raiz.item
        raiz = self.deletarMengo(item, raiz)
        if (raiz.item == None):
            del raiz
            return
        elif (raiz.item == itemAtual):
            if (raiz.black):
                self.itensRecentes[:] = [item for item in self.itensRecentes if item != raiz.item]
        raiz.black = True
        self.itensRecentes.append(self.itensRecentes.pop(0))
        self.itensRecentes.insert(0, None)
        return raiz
    # Remoçao binária comum, adicionada de reparaçao do balanceamento para a árvore rubro-negra
    # Certo momento é preciso considerar None como sendo um nodo None com black = 2,
    # ou seja, um None double black, porém é logo substituído por None.
    def deletarMengo(self, item, raiz):
        if (raiz == None): # Item nao encontrado
            self.itensRecentes.append(None)
            return raiz
        if (raiz.item == None): # nodo None double black
            return raiz
        if (item < raiz.item): # Recursa para à esquerda
            raiz.esq = self.deletarMengo(item, raiz.esq)
        elif (item > raiz.item): # Recursa para à direita
            raiz.dir = self.deletarMengo(item, raiz.dir)
        else:
            if (raiz.esq != None and raiz.dir != None): # Item localizado, porém contem ambos os ramos
                subs = self.delNodoSubstituto(raiz.esq) # Encontra-se o maior subsituto no ramo esquerdo
                self.itensRecentes.append(subs.item)
                raiz.item = subs.item # Troca-se os valores do atual e o substituo
                raiz.esq = self.deletarMengo(subs.item, raiz.esq) # Recursa, no ramo esquerdo, para deletar o novo nodo contendo o valor de item
            else: # Item (re)localizado, com pelo menos um ramo None
                if (raiz.esq == None): subs = raiz.dir # O substituto será uma filho "válido", se existente, senao None
                else: subs = raiz.esq
                if (subs != None):
                    self.itensRecentes.append(subs.item)
                else:
                    self.itensRecentes.append(None)
                if (self.isNodoRed(raiz) or self.isNodoRed(subs)): # Se ou filho substituto ou o atual for RED, basta setar o substituto para BLACK.
                    subs = self.setNodoToBlack(subs)
                else: subs = self.setNodoToDoubleBlack(subs) # Senao, o substituto torna-se double black(mesmo se for None), e será preciso rebalancear.
                
                del raiz
                return subs
        #if (raiz != None):
        # Rebalanceamento
        # Primeiro identifica-se o irmao e seu ramo
        irmao = None
        if (self.isNodoDoubleBlack(raiz.esq)):
            irmao = raiz.dir
            coxinha = True
        elif (self.isNodoDoubleBlack(raiz.dir)):
            irmao = raiz.esq
            coxinha = False
        if (irmao != None): # Se há um double black, haverá um irmao válido.
            if (irmao.black): # Se o irmao for BLACK
                if (coxinha): raiz.esq = self.setNodoToBlack(raiz.esq) # Desfaz-se a condiçao de double black do substituto
                else: raiz.dir = self.setNodoToBlack(raiz.dir)
                if (self.isNodoBlack(irmao.esq) and self.isNodoBlack(irmao.dir)): # Se os sobrinhos forem ambos BLACK (ou None)
                    irmao = self.setNodoToRed(irmao) # Irmao é colorido em RED
                    if (self.isNodoBlack(raiz)): raiz = self.setNodoToDoubleBlack(raiz) # Pai se torna double black se for black
                    else: raiz = self.setNodoToBlack(raiz) # Ou black se for RED (ou seja, nível de black é aumentado em 1)
                else: # Se pelo menos um sobrinho for vermelho
                    if (coxinha): # Irmao no ramo direito
                        if (self.isNodoBlack(irmao.dir)): # Right-Left, senao Right-Right
                            irmao = self.rotacaoDir(irmao)
                            irmao.dir, irmao = self.swapNodoCor(irmao.dir, irmao)
                        raiz.dir = irmao
                        raiz = self.rotacaoEsq(raiz)
                        raiz.esq, raiz = self.swapNodoCor(raiz.esq, raiz)
                        raiz.dir = self.setNodoToBlack(raiz.dir, black = self.isNodoBlack(raiz.esq))
                    else: # Irmao no ramo esquerdo
                        if (self.isNodoBlack(irmao.esq)): # Left-Right, senao Left-Left
                            irmao = self.rotacaoEsq(irmao)
                            irmao.esq, irmao = self.swapNodoCor(irmao.esq, irmao)
                        raiz.esq = irmao
                        raiz = self.rotacaoDir(raiz)
                        raiz.dir, raiz = self.swapNodoCor(raiz.dir, raiz)
                        raiz.esq = self.setNodoToBlack(raiz.esq, black = self.isNodoBlack(raiz.dir))
            # Se o irmao for RED, é feita algumas operaçoes de rotaçao e swap de cor,
            # para novamente se visitar o ramo do nodo substituto
            # Note que o nodo double-black nao foi desfeito ainda.
            else: 
                if (coxinha): # Se irmao no ramo esquerdo
                    raiz = self.rotacaoEsq(raiz)
                    raiz.esq, raiz = self.swapNodoCor(raiz.esq, raiz)
                    raiz.dir = self.setNodoToBlack(raiz.dir)
                    raiz.esq = self.deletarMengo(item, raiz.esq)
                else: # Se irmao no ramo direito
                    raiz = self.rotacaoDir(raiz)
                    raiz.dir, raiz = self.swapNodoCor(raiz.dir, raiz)
                    raiz.esq = self.setNodoToBlack(raiz.esq)
                    raiz.dir = self.deletarMengo(item, raiz.dir)
        return raiz
    # Reconstroi a árvore a partir de uma lista produzida pela funçao 'listaArvoreRB', abaixo
    def reinserir(self, item, black, raiz):
        if (raiz == None): return self.criarNodo(item, black)
        if (item < raiz.item):
            raiz.esq = self.reinserir(item, black, raiz.esq)
        elif (item > raiz.item):
            raiz.dir = self.reinserir(item, black, raiz.dir)
        return raiz
    def isFamiliaBlack(self, raiz):
        if (raiz == None or raiz.esq == None or raiz.dir == None): return False
        return self.isNodoBlack(raiz) and self.isNodoBlack(raiz.esq) and self.isNodoBlack(raiz.dir) and self.isNodoBlack(raiz.esq.esq) and self.isNodoBlack(raiz.esq.dir) and self.isNodoBlack(raiz.dir.esq) and self.isNodoBlack(raiz.dir.dir)
    def redistribuirCores(self, raiz):
        self.itensRecentes = [None]
        if (raiz == None): return
        fila = []
        filaAux = [raiz]
        familiasRed = False
        while filaAux:
            for nodo in filaAux:
                if (not self.isFamiliaBlack(nodo)):
                    familiasRed = True
            while filaAux:
                nodo = filaAux.pop()
                if (not familiasRed):
                    nodo.esq = self.setNodoToRed(nodo.esq)
                    nodo.dir = self.setNodoToRed(nodo.dir)
                    self.itensRecentes.extend([nodo.esq.item, nodo.dir.item])
                    fila.append(nodo.esq)
                    fila.append(nodo.dir)
                else:
                    fila.append(nodo)
            familiasRed = False
            while fila:
                nodo = fila.pop()
                if (nodo.esq != None):
                    filaAux.append(nodo.esq)
                if (nodo.dir != None):
                    filaAux.append(nodo.dir)
        self.itensRecentes.append(None)
        return raiz
    def pesquisar(self, item, raiz):
        if (raiz != None):
            if (item == raiz.item):
                return raiz
            elif (item < raiz.item):
                return self.pesquisar(item, raiz.esq)
            else:
                return self.pesquisar(item, raiz.dir)
        return
    # "Visita" a árvore pelo método da busca em largura (BFS)
    # e salva os dados da lista necessários para reconstruçao:
    # itensRecentes; nodos e suas respectivas cores.
    def listaArvoreRB(self, raiz):
        if (raiz == None): return
        fila = [raiz]
        lista = [self.itensRecentes[:]]
        while fila:
            nodo = fila.pop(0)
            if (nodo.esq != None):
                fila.append(nodo.esq)
            if (nodo.dir != None):
                fila.append(nodo.dir)
            lista.append((nodo.item,nodo.black))
        return lista
    def listaArvoreBFS(self, raiz):
        if (raiz == None): return
        fila = [raiz]
        lista = []
        while fila:
            nodo = fila.pop(0)
            if (nodo.esq != None):
                fila.append(nodo.esq)
            if (nodo.dir != None):
                fila.append(nodo.dir)
            lista.append(nodo.item)
        return lista
