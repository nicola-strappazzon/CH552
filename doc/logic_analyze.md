# Logic analyze

El dispositivo que vamos a configurar en Windows 11 es [nanoDLA](https://github.com/wuxx/nanoDLA), para otros sistemas operativos como MAC OS y Linux no hace falta. Una vez que este operativo, podra usar el software [Pulseview](pulseview.md) para capturar y explorar.

Al conectar el dispositivo en Windows 11 podemos verificar si lo reconoce haciendo uso del `Device Manager`, cómo se puede observar en `Other devices`, esta identificado cómo `fx2lafw`.

![](/assets/doc/logic_analyze/windows01.png)

Al no estar reconocido, deberá instalar el controlador mediante la herramienta `zadig`. Escriba la siguiente línea en el PowerShell:

```powershell
winget install 
```

Al iniciar `zadig`, detectará el dispositivo nuevo y podrá instalar el controlador:

![](/assets/doc/logic_analyze/windows02.png)

![](/assets/doc/logic_analyze/windows03.png)

![](/assets/doc/logic_analyze/windows04.png)

Una vez instalado el controlador, no se requiere reiniciar, y podra observar en el `Device Manager` que aparece en un nuevo sitio `Universal Serial Bus devices`.
