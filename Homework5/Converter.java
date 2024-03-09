public class Converter{

   public static String DecimalToBinary(int n){
      String ret = "";
      if (n == 0) {
              ret = "0";
              System.out.println(ret);
              return "0";
         }
         while (n > 0) {
              ret = n%2 + ret;
              n = n / 2;   
         }
         System.out.println(ret);
         return ret;   
   }
   
   public static int BinaryToDecimal(String bin){
      int decimalValue = Integer.parseInt(bin, 2);
      System.out.println(decimalValue);
      return decimalValue;
   }
   
   public static int myCode(String bin){
   
      int dec = 0;
      int holder = 0;
      
      for(int i = 0; i < bin.length(); i++){
         holder = Character.getNumericValue(bin.charAt(i));
         if(holder == 0){
         }
         else if(holder == 1){
            dec = dec + (int)Math.pow(2,i);
            }
         }
      System.out.println(dec);
      return dec;
  }
   
   public static void main(String args[]){
   
      DecimalToBinary(13);
      System.out.println();
      BinaryToDecimal("1001");
      System.out.println();
      myCode("101010101");
   }
}