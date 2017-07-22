       IDENTIFICATION DIVISION.
       PROGRAM-ID. game.

       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT DATOS ASSIGN TO "Game.txt" ORGANIZATION IS LINE
       SEQUENTIAL.

       DATA DIVISION.
       FILE SECTION.
       FD DATOS.
       01 DetalleJuego.
           88 FinArchivo VALUE HIGH-VALUES.
           02 Posicion PIC 9(9).
           02 Entrada PIC X(10).
           02 Direccion PIC X(17).
           02 Color PIC X(16).
           02 Acierto PIC X(10).
           02 Tiempo PIC 9(10).
           02 Nombre PIC X(15).
.
       WORKING-STORAGE SECTION.
       01 Operaciones.
           02 TOTALAZUL PIC 9(3) VALUES 000.
           02 TOTALROJO PIC 9(3) VALUES 000.
           02 TOTALAMARILLO PIC 9(3) VALUES 000.
           02 TOTALVERDE PIC 9(3) VALUES 000.
           02 CONTTOTALFLECHAS PIC 9(3) VALUES 000.
           02 CONT-FLECHA-IZQUIERDA PIC 9(3) VALUES 000.
           02 CONT-FLECHA-ARRIBA PIC 9(3) VALUES 000.
           02 CONT-FLECHA-ABAJO PIC 9(3) VALUES 000.
           02 CONT-FLECHA-DERECHA PIC 9(3) VALUES 000.
           02 TOTAL-FLECHAS PIC 9(3) VALUES 000.
           02 CONT-ERROR-FLECHA-IZQUIERDA PIC 9(3) VALUES 000.
           02 CONT-ERROR-FLECHA-ARRIBA PIC 9(3) VALUES 000.
           02 CONT-ERROR-FLECHA-ABAJO PIC 9(3) VALUES 000.
           02 CONT-ERROR-FLECHA-DERECHA PIC 9(3) VALUES 000.
           02 TOTAL-ERROR-FLECHAS PIC 9(3) VALUES 000
           02 CONTACIERTO PIC 9(3) VALUES 000.
           02 CONTERROR PIC 9(3) VALUES 000.
           02 USUARIO PIC X(15).
           02 USUARIO2 PIC X(15).
           02 TOTALACIERTO1 PIC 9(3) VALUES 000.
           02 TOTALACIERTO2 PIC 9(3) VALUES 000.
           02 TOTALERROR1 PIC 9(3) VALUES 000.
           02 TOTALERROR2 PIC 9(3) VALUES 000.
           02 TOTALPUNTOS1 PIC 9(4) VALUES 0000.
           02 TOTALPUNTOS2 PIC 9(4) VALUES 0000.
           02 DONTCLOSE PIC X(1).
       PROCEDURE DIVISION.
           DISPLAY "LEYENDO TODOS  LOS DATOS"
           OPEN INPUT DATOS.

      *> PRIMERA OPERACION
       
           READ DATOS AT END SET FinArchivo TO TRUE
           END-READ
           DISPLAY "1° OPERACION: PUNTAJE DEL USUARIO "
           DISPLAY "INGRESAR NOMBRE DE USUARIO"
           ACCEPT USUARIO
                   DISPLAY "Direccion          Color         Acierto",
                   "        Usuario"
                   DISPLAY "-----------------------------------------",
                   "--------------------------"
           PERFORM UNTIL FinArchivo
               IF Nombre = USUARIO THEN
                   DISPLAY Direccion SPACE 
                   Color SPACE Acierto SPACE Nombre
                   IF Acierto = "Si"  THEN
                       ADD 1 TO CONTACIERTO
                   END-IF
                   IF Acierto = "No" THEN
                       ADD 1 TO CONTERROR
                   END-IF

                   ADD 1 TO CONTTOTALFLECHAS

              END-IF
               
              READ DATOS
              AT END SET FinArchivo TO TRUE
              END-READ

           END-PERFORM

      *> RESULTADO DE BUSQUEDA POR ACIERTOS
           DISPLAY "--------------RESULTADOS---------------"
           DISPLAY "DATOS DEL USUARIO: ", USUARIO
           DISPLAY "   TOTAL ACIERTOS: ", CONTACIERTO
           DISPLAY "    TOTAL ERRORES: ", CONTERROR
           DISPLAY "    TOTAL FLECHAS: ", CONTTOTALFLECHAS
           DISPLAY "--------------------------------------"
 
       CLOSE DATOS
       
      *>SEGUNDA OPERACION

       OPEN INPUT DATOS.
       READ DATOS
       AT END SET FinArchivo TO TRUE
       END-READ

       DISPLAY "2° OPERACION: DETALLE DE FLECHAS"

       DISPLAY "INGRESAR USUARIO: "
       ACCEPT USUARIO

      *> INICIALIZAMOS CONTTOTALFLECHAS
       COMPUTE CONTTOTALFLECHAS = 0
       PERFORM UNTIL FinArchivo
           IF Nombre = USUARIO THEN
               IF Acierto = "Si"
                   IF Direccion = "izquierda" THEN
                      ADD 1 TO CONT-FLECHA-IZQUIERDA
                   END-IF
                   IF Direccion ="arriba" THEN
                       ADD 1 TO CONT-FLECHA-ARRIBA
                   END-IF
                   IF Direccion="abajo" THEN
                       ADD 1 TO CONT-FLECHA-ABAJO
                   END-IF
                   IF Direccion="derecha" THEN
                       ADD 1 TO CONT-FLECHA-DERECHA
                   END-IF
                   ADD 1 TO TOTAL-FLECHAS
               END-IF

                IF Acierto = "No"
                   IF Direccion = "izquierda" THEN
                      ADD 1 TO CONT-ERROR-FLECHA-IZQUIERDA
                   END-IF
                   IF Direccion ="arriba" THEN
                       ADD 1 TO CONT-ERROR-FLECHA-ARRIBA
                   END-IF
                   IF Direccion="abajo" THEN
                       ADD 1 TO CONT-ERROR-FLECHA-ABAJO
                   END-IF
                   IF Direccion="derecha" THEN
                       ADD 1 TO CONT-ERROR-FLECHA-DERECHA
                   END-IF
                   ADD 1 TO TOTAL-ERROR-FLECHAS
               END-IF
           END-IF

       READ DATOS
       AT END SET FinArchivo  TO TRUE
       END-READ

       END-PERFORM

       *> RESULTADO DE BUSQUEDA POR ACIERTOS
           DISPLAY "--------------RESULTADOS---------------"
           DISPLAY "DATOS DEL USUARIO: ", USUARIO
           DISPLAY " "
           DISPLAY "------------------------------------------"
           DISPLAY " | DIRECCIÓN" SPACE
           "| ACERTADOS | " SPACE "ERROR | "
           DISPLAY "------------------------------------------"

           DISPLAY " | IZQUIERDA | ",
           "   " ,CONT-FLECHA-IZQUIERDA, "    |   ",
           CONT-ERROR-FLECHA-IZQUIERDA,"  |"                         

           DISPLAY " | ARRIBA    |",
           "    " ,CONT-FLECHA-ARRIBA, "    |   ",
           CONT-ERROR-FLECHA-ARRIBA, "  |"

           DISPLAY " | ABAJO     |",
           "    ", CONT-FLECHA-ABAJO, "    |   ",
           CONT-ERROR-FLECHA-ABAJO, "  |"

           DISPLAY " | DERECHA   |",
           "    ", CONT-FLECHA-DERECHA, "    |   ",
           CONT-ERROR-FLECHA-DERECHA, "  |"
           DISPLAY "------------------------------------------"
           DISPLAY "    TOTAL", "         ", TOTAL-FLECHAS, "        ",
           TOTAL-ERROR-FLECHAS
           DISPLAY "--------------------------------------"

       CLOSE DATOS

       *> TERCERA OPERACION
       OPEN INPUT DATOS

       READ DATOS
       AT END SET FinArchivo TO TRUE
       END-READ

       DISPLAY "3° OPERACION: COMPARAR PUNTAJE DE DOS USUARIOS"
       DISPLAY " "
       DISPLAY "--------JUGADORES--------"
       DISPLAY "Ingresar Primer Jugador "
       ACCEPT USUARIO
       DISPLAY "-----------VS------------"
       DISPLAY "Ingresar Segundo Jugador: "
       ACCEPT USUARIO2

       PERFORM UNTIL FinArchivo

           IF Nombre  = USUARIO THEN
               IF Acierto = "Si" THEN
                   ADD 1 TO TOTALACIERTO1
               END-IF
               IF Acierto = "No" THEN
                   ADD 1 TO TOTALERROR1;
               END-IF
               
           END-IF

           IF Nombre = USUARIO2 THEN
               IF Acierto = "Si" THEN
                   ADD 1 TO TOTALACIERTO2
               END-IF
               IF Acierto = "No" THEN
                   ADD 1 TO TOTALERROR2    
               END-IF
               
           END-IF


           READ DATOS
           AT END SET FinArchivo TO TRUE
           END-READ
       END-PERFORM

          DISPLAY "------------ RESULTADO ---------------"
          DISPLAY "RESULTADO DE ", USUARIO
                      
               IF TOTALACIERTO1 > TOTALERROR1 THEN

                   SUBTRACT TOTALACIERTO1 FROM TOTALERROR1 GIVING
                   TOTALPUNTOS1

                   DISPLAY "   PUNTOS OBTENIDOS:  ", TOTALPUNTOS1
                
               ELSE IF TOTALACIERTO1 < TOTALERROR1 THEN

                   SUBTRACT TOTALERROR1 FROM TOTALACIERTO1 GIVING
                   TOTALPUNTOS1

                   DISPLAY "   RESTAS: ", TOTALPUNTOS1

                    ELSE
                        DISPLAY "NO CUENTAS CON NINGUN PUNTAJE"
                    END-IF

               END-IF

          DISPLAY "RESULTADO DE ", USUARIO2
               IF TOTALACIERTO2 > TOTALERROR2 THEN

                   SUBTRACT TOTALACIERTO2 FROM TOTALERROR2 GIVING
                   TOTALPUNTOS2

                   DISPLAY "   PUNTOS OBTENIDOS:  ", TOTALPUNTOS2
                
               ELSE IF TOTALACIERTO2 < TOTALERROR2 THEN

                   SUBTRACT TOTALERROR2 FROM TOTALACIERTO2 GIVING
                   TOTALPUNTOS2

                   DISPLAY "   RESTAS: ", TOTALPUNTOS2

                    ELSE
                        DISPLAY "NO CUENTAS CON NINGUN PUNTAJE"
                    END-IF

               END-IF
        
          DISPLAY "---------------------------------------"

       CLOSE DATOS

       ACCEPT DONTCLOSE;
       STOP RUN.
 
       END PROGRAM game.