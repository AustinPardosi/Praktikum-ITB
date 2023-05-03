public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
        int i = 0;
        int idx = 0;
        int found = 0;
        boolean result = true;
        String message;
        if (this.email.length() > 0) {
            while (i < this.email.length()) {
                if (this.email.charAt(i) == '@') {
                    found += 1;
                    idx = i;
                }
                i++;
            }

            if (found != 1) {
                message = "Email harus mengandung tepat satu buah @";
                result = false;
                throw new InvalidEmailException(message);
            }

            if (idx == 0) {
                message = "@ tidak boleh di awal email";
                result = false;
                throw new InvalidEmailException(message);
            }
            
            if ((this.email.indexOf(".com") == idx+1) || (this.email.indexOf(".com") == -1)) {
                result = false;
                throw new InvalidDomainException();
            }
        } else {
            message = "Email tidak boleh kosong";
            result = false;
            throw new InvalidEmailException(message);
        }
        return result;
    }

}

class InvalidEmailException extends Exception{
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        super(message);
    }
}

class InvalidDomainException extends Exception{
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
        return "Email harus memiliki domain yang valid";
    }
}