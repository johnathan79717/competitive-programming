<?
  $tempdata = array( "showpassword"=>"yes", "bgcolor"=>"#ffffff");
  $text = json_encode($tempdata);
  $outText = "";
  $key = "qw8J";
  for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
  }
  echo base64_encode($outText);
?>