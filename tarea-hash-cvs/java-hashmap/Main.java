import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {

        System.out.println("Nombre: Carlos Daniel Castro Caceres");
        System.out.println("Carne: 9941-24-10004");

        HashMap<Integer, Estudiante> estudiantes =
                new HashMap<>();

        cargarCSV("estudiantes.csv", estudiantes);

        System.out.println("\nTOTAL ESTUDIANTES: "
                + estudiantes.size());

        System.out.println("\n===== HASHMAP =====");

        for(Integer key : estudiantes.keySet()) {

            System.out.println(
                    "\nClave: " + key);

            System.out.println(
                    estudiantes.get(key));

        }

        buscar(estudiantes, 1002);

        eliminar(estudiantes, 1003);

        System.out.println(
                "\nTOTAL DESPUES DE ELIMINAR: "
                + estudiantes.size());

    }

    public static void cargarCSV(
            String archivo,
            HashMap<Integer, Estudiante> estudiantes
    ) {

        try {

            BufferedReader br =
                    new BufferedReader(
                            new FileReader(archivo));

            String linea;

            br.readLine();

            while((linea = br.readLine()) != null) {

                String[] datos =
                        linea.split(",");

                int id =
                        Integer.parseInt(datos[0]);

                if(estudiantes.containsKey(id)) {

                    System.out.println(
                            "Duplicado: " + id);

                    continue;

                }

                Estudiante e =
                        new Estudiante(
                                id,
                                datos[1],
                                datos[2],
                                Integer.parseInt(datos[3]),
                                Double.parseDouble(datos[4]),
                                Integer.parseInt(datos[5])
                        );

                estudiantes.put(id, e);

            }

            br.close();

        } catch(Exception e) {

            System.out.println(
                    "Error: " + e.getMessage());

        }

    }

    public static void buscar(
            HashMap<Integer, Estudiante> estudiantes,
            int id
    ) {

        System.out.println(
                "\n===== BUSQUEDA =====");

        if(estudiantes.containsKey(id)) {

            System.out.println(
                    estudiantes.get(id));

        } else {

            System.out.println(
                    "Estudiante no encontrado");

        }

    }

    public static void eliminar(
            HashMap<Integer, Estudiante> estudiantes,
            int id
    ) {

        System.out.println(
                "\n===== ELIMINACION =====");

        if(estudiantes.containsKey(id)) {

            estudiantes.remove(id);

            System.out.println(
                    "Estudiante eliminado");

        } else {

            System.out.println(
                    "Estudiante no encontrado");

        }

    }

}